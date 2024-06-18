#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 22
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 18
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  anon_sym_abs_LPAREN = 3,
  anon_sym_max = 4,
  anon_sym_min = 5,
  anon_sym_LPAREN2 = 6,
  anon_sym_COMMA = 7,
  sym_constant = 8,
  sym_identifier = 9,
  anon_sym_PLUS = 10,
  anon_sym_DASH = 11,
  anon_sym_STAR = 12,
  anon_sym_SLASH = 13,
  anon_sym_CARET = 14,
  sym_expression = 15,
  sym_builtin = 16,
  sym_arithmetic = 17,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_abs_LPAREN] = "abs(",
  [anon_sym_max] = "max",
  [anon_sym_min] = "min",
  [anon_sym_LPAREN2] = "(",
  [anon_sym_COMMA] = ",",
  [sym_constant] = "constant",
  [sym_identifier] = "identifier",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_CARET] = "^",
  [sym_expression] = "expression",
  [sym_builtin] = "builtin",
  [sym_arithmetic] = "arithmetic",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_abs_LPAREN] = anon_sym_abs_LPAREN,
  [anon_sym_max] = anon_sym_max,
  [anon_sym_min] = anon_sym_min,
  [anon_sym_LPAREN2] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_constant] = sym_constant,
  [sym_identifier] = sym_identifier,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_CARET] = anon_sym_CARET,
  [sym_expression] = sym_expression,
  [sym_builtin] = sym_builtin,
  [sym_arithmetic] = sym_arithmetic,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_abs_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_max] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_min] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_builtin] = {
    .visible = true,
    .named = true,
  },
  [sym_arithmetic] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_paren = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_paren] = "paren",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_paren, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '"', 11,
        '(', 19,
        ')', 15,
        '*', 26,
        '+', 24,
        ',', 20,
        '-', 25,
        '/', 27,
        '^', 28,
        'a', 6,
        'm', 5,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(11);
      if (lookahead == '(') ADVANCE(14);
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == 'a') ADVANCE(6);
      if (lookahead == 'm') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(19);
      END_STATE();
    case 4:
      if (lookahead == '(') ADVANCE(16);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'b') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 's') ADVANCE(4);
      END_STATE();
    case 9:
      if (lookahead == 'x') ADVANCE(17);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 12:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '"', 11,
        '(', 14,
        ')', 15,
        '*', 26,
        '+', 24,
        ',', 20,
        '-', 25,
        '/', 27,
        '^', 28,
        'a', 6,
        'm', 5,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_abs_LPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_max);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_min);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LPAREN2);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_constant);
      if (lookahead == '.') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_constant);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_identifier);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 1},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 3},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_abs_LPAREN] = ACTIONS(1),
    [anon_sym_max] = ACTIONS(1),
    [anon_sym_min] = ACTIONS(1),
    [anon_sym_LPAREN2] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
  },
  [1] = {
    [sym_expression] = STATE(19),
    [sym_builtin] = STATE(9),
    [sym_arithmetic] = STATE(9),
    [anon_sym_LPAREN] = ACTIONS(3),
    [anon_sym_abs_LPAREN] = ACTIONS(5),
    [anon_sym_max] = ACTIONS(7),
    [anon_sym_min] = ACTIONS(7),
    [sym_constant] = ACTIONS(9),
    [sym_identifier] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(18), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [22] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(16), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [44] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(17), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [66] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(20), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [88] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(14), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [110] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(12), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [132] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      anon_sym_abs_LPAREN,
    STATE(13), 1,
      sym_expression,
    ACTIONS(7), 2,
      anon_sym_max,
      anon_sym_min,
    ACTIONS(9), 2,
      sym_constant,
      sym_identifier,
    STATE(9), 2,
      sym_builtin,
      sym_arithmetic,
  [154] = 1,
    ACTIONS(11), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
  [165] = 1,
    ACTIONS(13), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
  [176] = 1,
    ACTIONS(15), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
  [187] = 3,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(17), 5,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
  [202] = 2,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(17), 7,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
  [215] = 1,
    ACTIONS(17), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
  [226] = 1,
    ACTIONS(23), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
  [237] = 4,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [252] = 4,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(29), 1,
      anon_sym_RPAREN,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [267] = 4,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(31), 1,
      anon_sym_COMMA,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [282] = 4,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [297] = 4,
    ACTIONS(21), 1,
      anon_sym_CARET,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    ACTIONS(19), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [312] = 1,
    ACTIONS(37), 1,
      anon_sym_LPAREN2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 22,
  [SMALL_STATE(4)] = 44,
  [SMALL_STATE(5)] = 66,
  [SMALL_STATE(6)] = 88,
  [SMALL_STATE(7)] = 110,
  [SMALL_STATE(8)] = 132,
  [SMALL_STATE(9)] = 154,
  [SMALL_STATE(10)] = 165,
  [SMALL_STATE(11)] = 176,
  [SMALL_STATE(12)] = 187,
  [SMALL_STATE(13)] = 202,
  [SMALL_STATE(14)] = 215,
  [SMALL_STATE(15)] = 226,
  [SMALL_STATE(16)] = 237,
  [SMALL_STATE(17)] = 252,
  [SMALL_STATE(18)] = 267,
  [SMALL_STATE(19)] = 282,
  [SMALL_STATE(20)] = 297,
  [SMALL_STATE(21)] = 312,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 3, 0, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_builtin, 3, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arithmetic, 3, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_builtin, 6, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [33] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_expr(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
