package expr

import (
	"context"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestArithmeticBasic(t *testing.T) {
	b, err := NewBuilder()
	if err != nil {
		t.Fatal(err)
	}
	defer b.Close()
	expr, err := b.Build(context.TODO(), "1 + (2 + 2) * 3 ^ 2 / 4")
	if err != nil {
		t.Fatal(err)
	}
	v, err := expr.Eval()
	if err != nil {
		t.Fatal(err)
	}
	assert.InDelta(t, v, 10, 1e-9)
}
