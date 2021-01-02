#include <stdio.h>
#include <stdlib.h>
#include "quad.h"
#include "list.h"
#include "symbol_table.h"
#include "yacc_util.h"
#include "yacc.tab.h"
#include "context.h"

liste *creelist(size_t eti) {
  liste *newlist = (liste *) malloc(sizeof(liste));
  if (newlist==NULL) {
    fprintf(stderr, "Erreurn malloc\n");
    exit(EXIT_FAILURE);
  }
  newlist->quad_eti = eti;
  newlist->next = NULL;

  return newlist;
}

liste *concat3(liste *l1, liste *l2, liste *l3) {

  return concat(concat(l1, l2), l3);
}

liste *concat(liste *l1, liste *l2) {

  if (l1==NULL)
    return l2;

  while (l1->next!=NULL)
    l1 = l1->next;
  l1->next = l2;

  return l1;
}

int contains(liste *l, size_t eti)
{
  while (l->next != NULL)
  {
    if (l->quad_eti == eti)
      return 1;
    l = l->next;
  }
  return 0;
}

int last(liste *l)
{
  int res = l->quad_eti;
  while (l->next != NULL)
  {
    res = l->quad_eti;
    l = l->next;
  }
  return res;
}

void complete(liste *l, size_t eti) {
  while (l!=NULL) {
    current_context->quad_table[l->quad_eti].res = quadop_etiquette(eti);
    l = l->next;
  }
  current_context->quad_table[eti].label = 1;
}

void free_list(liste *l) {
  liste *tmp;
  while (l!=NULL) {
    tmp = l;
    l = l->next;
    free(tmp);
  }
}

void print_liste(liste *l) {
  liste *copy = l;
  while (copy->next!=NULL) {
    printf("%zu ", copy->quad_eti); //%zu pour print long unsigned int
    copy = copy->next;
  }
  printf("%zu\n", copy->quad_eti);
}


interval_list* cree_interval(int inf, int sup){
  interval_list* newi = (interval_list*) malloc(sizeof(interval_list));
  if (newi==NULL){
    fprintf(stderr, "Erreur malloc dans cree_interval()\n");
    exit(EXIT_FAILURE);
  }

  newi->inf = inf;
  newi->sup = sup;
  newi->taille = sup-inf+1;
  newi->next = NULL;

  return newi;
}


interval_list* concat_interval(interval_list* range1, interval_list* range2){
  if (range1==NULL)
    return range2;

  interval_list* copy = range1;
  while(copy->next!=NULL)
    copy=copy->next;
  
  copy->next = range2;
  
  return range1;
}

arrind* cree_arrind(quadop quadop){
  arrind* new = (arrind*) malloc(sizeof(arrind));
  if (new==NULL){
    fprintf(stderr,"Erreur malloc dans cree_arrind()\n");
    exit(EXIT_FAILURE);
  }

  new->quadop = quadop;
  new->next = NULL;

  return new;
}

arrind* concat_arrind(arrind* a1, arrind* a2){
  if (a1==NULL)
    return a2;

  arrind* copy = a1;
  while(copy->next!=NULL)
    copy=copy->next;

  copy->next = a2;

  return a1;
}

identifierlist *creeidentlist(char *name)
{
  identifierlist *new = (identifierlist *)malloc(sizeof(identifierlist));
  if (new == NULL)
  {
    fprintf(stderr, "Erreur malloc dans cree_identifierlist()\n");
    exit(EXIT_FAILURE);
  }

  new->name = name;
  new->next = NULL;

  return new;
}

identifierlist *concatidentlist(identifierlist *l1, identifierlist *l2)
{
  if (l1 == NULL)
    return l2;

  identifierlist *copy = l1;
  while (copy->next != NULL)
    copy = copy->next;

  copy->next = l2;

  return l1;
}
