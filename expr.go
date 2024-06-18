package expr

// #cgo CFLAGS: -std=c11 -fPIC
// #include "./src/parser.c"
import "C"
import (
	"context"
	"errors"
	"fmt"
	"math"
	"strconv"
	"strings"
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

var (
	ErrParsing         = errors.New("parse error")
	ErrEmptyExpression = fmt.Errorf("%w: empty expression", ErrParsing)
	ErrEmptyConstant   = fmt.Errorf("%w: empty constant", ErrParsing)
)

// Get the tree-sitter Language for this grammar.
func Language() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_expr())
}

func NewBuilder() (*Builder, error) {
	parser := sitter.NewParser()
	lang := sitter.NewLanguage(Language())
	if lang == nil {
		return nil, errors.New("error loading grammar")
	}
	parser.SetLanguage(lang)
	return &Builder{parser}, nil
}

type Builder struct {
	parser *sitter.Parser
}

func (b *Builder) Close() {
	b.parser.Close()
}

func (b *Builder) build(expr string, node *sitter.Node) (Expression, error) {
	for i := uint32(0); i < node.ChildCount(); i++ {
		child := node.Child(int(i))
		// nodeDebug(expr, child)
		// Validation.
		{
			var err error
			if child.IsError() {
				err = ErrParsing
			} else if child.Symbol() == C.sym_constant && child.StartByte() == child.EndByte() {
				err = ErrEmptyConstant
			}
			if err != nil {
				content := expr[child.StartByte():child.EndByte()]
				return nil, fmt.Errorf("%w: %s", err, content)
			}
		}
		switch child.Symbol() {
		case C.sym_expression:
			return b.build(expr, child)
		case C.sym_constant:
			return NewConstantExpression(expr[child.StartByte():child.EndByte()])
		case C.sym_arithmetic:
			if child.ChildCount() != 3 {
				return nil, errors.New("arithmetic rule has wrong number of children")
			}
			op := ExprAt(expr, child.Child(1))
			left, err := b.build(expr, child.Child(0))
			if err != nil {
				return nil, err
			}
			right, err := b.build(expr, child.Child(2))
			if err != nil {
				return nil, err
			}
			return NewArithmeticExpression(op, left, right)
		default:
			// println("skipping", child.Type())
		}
	}
	panic("unreachable")
}

func (b *Builder) Build(ctx context.Context, expr string) (Expression, error) {
	tree, err := b.parser.ParseCtx(ctx, nil, []byte(expr))
	if err != nil {
		return nil, err
	}
	defer tree.Close()
	return b.build(expr, tree.RootNode())
}

type Expression interface {
	Eval() (float64, error)
}

const AritmeticTokens = "+-/*^"

func NewArithmeticExpression(opToken string, left, right Expression) (Expression, error) {
	if left == nil {
		return nil, errors.New("got nil LHS")
	}
	if right == nil {
		return nil, errors.New("got nil RHS")
	}
	// Validate arithmetic token.
	if len(opToken) != 1 {
		return nil, errors.New("token has length not equal to one")
	}
	op := opToken[0]
	if strings.IndexByte(AritmeticTokens, op) < 0 {
		return nil, errors.New("got token outside of arithmetic token set")
	}
	return &arithmeticExpr{op: op, left: left, right: right}, nil
}

type arithmeticExpr struct {
	op          byte
	left, right Expression
}

func (a *arithmeticExpr) Eval() (float64, error) {
	l, err := a.left.Eval()
	if err != nil {
		return l, err
	}
	r, err := a.right.Eval()
	if err != nil {
		return r, err
	}
	switch a.op {
	case '+':
		return l + r, nil
	case '-':
		return l - r, nil
	case '/':
		if r == 0 {
			return math.NaN(), nil
		}
		return l / r, nil
	case '*':
		return l * r, nil
	case '^':
		if l == 0 && r < 1 {
			return math.NaN(), nil
		}
		return math.Pow(l, r), nil
	}
	return math.NaN(), errors.New("unreachable")
}

func NewConstantExpression(token string) (Expression, error) {
	res, err := strconv.ParseFloat(token, 64)
	if err != nil {
		return constantExpr(0), err
	}
	return constantExpr(res), nil
}

type constantExpr float64

func (c constantExpr) Eval() (float64, error) {
	return float64(c), nil
}

func ExprAt(expr string, n *sitter.Node) string {
	return expr[n.StartByte():n.EndByte()]
}

func nodeDebug(expr string, node *sitter.Node) {
	var indent string
	for cur := node; cur.Parent() != nil; cur = cur.Parent() {
		indent += "  "
	}
	fmt.Printf("%s%s: %s\n", indent, node.Type(), ExprAt(expr, node))
}
