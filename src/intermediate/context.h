#ifndef ESCALE_PAS_PARSER_SRC_CONTEXT_TABLE_H_
#define ESCALE_PAS_PARSER_SRC_CONTEXT_TABLE_H_

#include "quad.h"
#include "symbol_table.h"

typedef struct context_s {
  const char *function_name; /* vaut NULL pour le context global */
  entry symbol_table[SIZE];
  quad *quad_table;
  size_t nextquad;
  struct context_s *parent;
} context_t;

extern context_t *current_context;

context_t *newcontext(void);
void pushcontext(const char *function_name);
void popcontext(void);
void print_symbol_table(context_t *context);
void print_quad_table(context_t *context);

#endif
