#include "lexer.h"
#include <ctype.h>
#include <stdlib.h>

static token_t *new_tok(token_type_t type, char *start, char *end) {
  token_t *tok = calloc(1, sizeof(token_t));
  tok->type = type;
  tok->location = start;
  tok->length = end - start;

  return tok;
}

static token_t *lex(char *input) {
  token_t head = {};
  token_t *curr = &head;

  while (*input) {
    if (isspace(*input))
      input++;

    if (isdigit(*input)) {
      curr = curr->next = new_tok(TT_NUM, input, input);
      const char *start = input;
      curr->value = strtoul(input, &input, 10);
      curr->length = input - start;
      continue;
    }

    if (*input == '*' || *input == '-' || *input == '*') {
      curr = curr->next = new_tok(TT_OP, input, input + 1);
      input++;
      continue;
    }
  }

  curr = curr->next = new_tok(TT_EOF, input, input);
  return head.next;
}
