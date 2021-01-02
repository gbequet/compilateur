#include <stdlib.h>
#include <stdio.h>

void lookup_error(char *symbol) {

  fprintf(stderr, "Error: Symbol '%s' is not declared\n", symbol);
  exit(1);
}

void type_error(void) {
  fprintf(stderr, "Error: Type mismatch\n");
  exit(1);
}


void nb_args_error(int params, int args) {
  fprintf(stderr, "Error: Function nb args does not match: %d != %d\n", params, args);
  exit(1);
}
