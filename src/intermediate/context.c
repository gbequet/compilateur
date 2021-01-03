#include <stdio.h>
#include <string.h>
#include "context.h"
#include "assembler.h"

void print_quad_table(context_t *context) {

  printf("\n\nGLOBAL CODE:\n\n");
  for (size_t i = 0; i < context->nextquad; ++i) {
    printf("%lu: ", i);
    print_quad(&context->quad_table[i]);
    printf("\n");
  }
}

static const char *show_atomic_type(type_e type) {

  switch (type) {

    case TYPE_INT:    return "int";
    case TYPE_BOOL:   return "bool";
    case TYPE_STRING: return "string";
    case TYPE_UNIT:   return "unit";
    case TYPE_FUNC:   return "func";
    case TYPE_ARRAY:  return "array";

    default: return "type not handled";
  }

}

static void print_typename(struct typedesc typedesc) {

  printf("%s", show_atomic_type(typedesc.type));

  if (typedesc.type==TYPE_FUNC) {
    char *comma = "";
    printf("(");
    for (int i = 0; i < typedesc.nb_params; ++i) {
      printf("%s%s", comma, show_atomic_type(typedesc.params[i]));
      comma = ", ";
    }
    printf("): %s", show_atomic_type(typedesc.returntype));
  }
}

void print_symbol_table(context_t *context) {
  printf("\n\nSYMBOL TABLE:\n\n");

  for (int i = 0; i < SIZE; i++) {
    if (context->symbol_table[i].id!=NULL) {
      printf("%d | %s -> type<", i, context->symbol_table[i].id);
      print_typename(context->symbol_table[i].typedesc);
      printf(">");

      if (context->symbol_table[i].typedesc.type == TYPE_ARRAY)
      {
        printf(" of ");
        printf("%s ", show_atomic_type(context->symbol_table[i].valtype));
        printf("de dimension %d", context->symbol_table[i].nb_dim);
        interval_list *intervals = context->symbol_table[i].rangelist;
        int k=0;
        while (k < context->symbol_table[i].nb_dim)
        {
          printf(", [%d .. %d]", intervals->inf, intervals->sup);
          intervals = intervals->next;
          k++;
        }
      }

      if (context->symbol_table[i].nbparams!=-1)
        printf(", nb_params[%d]", context->symbol_table[i].nbparams);

      printf("\n");
    }
  }
}

void pushcontext(const char *function_name) {
  context_t *new_context = newcontext();

  new_context->function_name = strdup(function_name);

  current_context = new_context;
}

void popcontext(void) {
  printf(">>> POP CONTEXT [%s] >>>\n", current_context->function_name);

  genmips(current_context);

  current_context = current_context->parent;
}

context_t *newcontext(void) {
  context_t *newcontext = calloc(1, sizeof(context_t));

  newcontext->quad_table = NULL;
  newcontext->parent = current_context;
  newcontext->nextquad = 0;

  return newcontext;
}
