const DIGIT = /[0-9]/;
const ALPHANUMERIC = /[0-9a-zA-Z]/;

const NUMBER = token(
  seq(optional("-"), repeat1(DIGIT), optional(seq(".", repeat(DIGIT)))),
);

const IDENTIFIER = token(seq('"', repeat1(ALPHANUMERIC), '"'));

module.exports = grammar({
  name: "expr",
  rules: {
    expression: ($) =>
      choice(
        prec(4, seq("(", field("paren", $.expression), ")")),
        $.builtin,
        $.constant,
        $.identifier,
        $.arithmetic,
      ),
    builtin: ($) =>
      choice(
        seq("abs(", $.expression, ")"),
        seq(
          choice("max", "min"),
          token.immediate("("),
          $.expression,
          ",",
          $.expression,
          ")",
        ),
      ),
    constant: () => NUMBER,
    identifier: () => IDENTIFIER,
    arithmetic: ($) =>
      prec.left(
        choice(
          prec(1, seq($.expression, choice("+", "-"), $.expression)),
          prec(2, seq($.expression, choice("*", "/"), $.expression)),
          prec(3, seq($.expression, "^", $.expression)),
        ),
      ),
  },
});
