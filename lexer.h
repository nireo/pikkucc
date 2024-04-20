#ifndef __PIKKUCC_LEXER_H
#define __PIKKUCC_LEXER_H

typedef enum {
  TT_NUM,
  TT_OP,
  TT_EOF,
} token_type_t;

typedef struct token_t {
  token_type_t type;
  struct token_t *next; // linked list
  int value;
  char *location;
  int length;
} token_t;

#endif
