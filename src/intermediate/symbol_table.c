#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "quad.h"
#include "list.h"
#include "symbol_table.h"
#include "yacc_util.h"
#include "yacc.tab.h"
#include "context.h"

int nb_var = 0;

/* renvoie l'index du caractere dans current_context->symbol_table */
int hash(const char *symbol) {
  int val = 0;
  for (int i = 0; symbol[i]!='\0'; i++) {
    val += symbol[i];
  }
  val %= SIZE;
  return val;
}

/* recherche l'indice de l'identificateur dans la table des symboles */
entry *lookup(char *symbol)
{
  context_t *iterator = current_context;

  while (iterator != NULL)
  {
    int index = hash(symbol);
    if (current_context->symbol_table[index].id != NULL)
    {
      while ((current_context->symbol_table[index].id != NULL) &&
             (strcmp(current_context->symbol_table[index].id, symbol) != 0))
        index = (index + 1) % SIZE;
      if (current_context->symbol_table[index].id == NULL)
        return NULL;
      else
        return &current_context->symbol_table[index];
    }

    iterator = iterator->parent;
  }

  return NULL;
}

/* ajoute un nouvel identificateur a current_context->symbol_table */
entry *newname(char *symbol) {
  int index = hash(symbol);
  while (current_context->symbol_table[index].id!=NULL) {
    if (strcmp(current_context->symbol_table[index].id, symbol)==0)
      break;
    index = (index + 1)%SIZE;
  }
  current_context->symbol_table[index].id = strdup(symbol);
  current_context->symbol_table[index].reg = -1;
  current_context->symbol_table[index].mem_adr = -1;
  current_context->symbol_table[index].last_use = -1;
  current_context->symbol_table[index].nbparams = -1;
  current_context->symbol_table[index].addr_pile = -1;
  current_context->symbol_table[index].typedesc = (struct typedesc){.type = -1, .nb_params = 0};
  current_context->symbol_table[index].nb_dim = -1;
  current_context->symbol_table[index].rangelist = NULL;
  current_context->symbol_table[index].valtype = TYPE_X;
  nb_var++;

  return &current_context->symbol_table[index];
}

void check_function_type(struct typedesc functype, struct typelist args) {

  if (functype.nb_params != args.nb_types)
    nb_args_error(functype.nb_params, args.nb_types);

  for (int i = 0; i < args.nb_types; ++i) {

    if (args.typelist[i].type == TYPE_FUNC)
      if (args.typelist[i].returntype != functype.params[i])
        type_error();

    if (args.typelist[i].type!=functype.params[i])
      type_error();
  }
}

void update_use(char *symbol, int numl) {
  entry *entry = lookup(symbol);
  entry->last_use = numl;
}

void update_mem(char *symbol, int mem_adr) {
  entry *entry = lookup(symbol);
  entry->mem_adr = mem_adr;
}

void update_reg(char *symbol, int reg) {
  entry *entry = lookup(symbol);
  entry->reg = reg;
}
