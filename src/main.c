#include <stdio.h>
#include <string.h>
#include "quad.h"
#include "list.h"
#include "symbol_table.h"
#include "yacc_util.h"
#include "yacc.tab.h"
#include "context.h"

context_t *current_context;
extern FILE *yyin;
int print_tos = 0;        // 1 si -tos rencontré dans argv
int print_globalcode = 0; // 1 si -quad rencontré dans argv

int main(int argc, char **argv)
{
  int i;
  
  if (argc<2) {
    printf("USAGE: ./scalpa <scalpa_src_file> [-o <name>][-tos][-version][-quad]\n");
    return 1;
  }

 yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
    perror("Erreur fopen() dans main()\n"
           "USAGE: ./scalpa <scalpa_src_file> [-o <name>][-tos][-version][-quad]\n");
    exit(EXIT_FAILURE);
  }

  yyout = fopen("prog.asm", "w");
  if (yyout==NULL){
    perror("Erreur fopen() dans main()");
    exit(EXIT_FAILURE);
  }

  context_t *main_context = newcontext();
  current_context = main_context;
  main_context->function_name = "main";

  newname("varXOR");

  for (i=2; i< argc; i++){
    if(strcmp(argv[i], "-version")==0){
      printf("\n\nMembres du projet:\n"
      "BEQUET Guillaume\nDELLALI Karim\n"
      "NASSABAIN Leonardo\nTEISSEIRE Arthur\n\n");
    }

    else if ((strcmp(argv[i], "-o")==0) && (i< argc -1)){
      if (fclose(yyout)==EOF){
        perror("Erreur fclose() dans main()");
        exit(EXIT_FAILURE);
      }
      if (remove("prog.asm")==-1){
        perror("Erreur remove() dans main()");
        exit(EXIT_FAILURE);
      }
      yyout = fopen(argv[i+1], "w");
      if (yyout==NULL){
        perror("Erreur fopen() dans main()");
        exit(EXIT_FAILURE);
      }
    }

    if (strcmp(argv[i], "-tos")==0){
      print_tos = 1;
    }

    if (strcmp(argv[i], "-quad")==0){
      print_globalcode = 1;
    }
  }

  do {
    yyparse();
  } while (!feof(yyin));

  popcontext();

  if (print_tos == 1)
    print_symbol_table(main_context);

  if (print_globalcode == 1)
    print_quad_table(main_context);

  if (fclose(yyin)==EOF){
    perror("Erreur fclose() dans main()");
    exit(EXIT_FAILURE);
  }
  if (fclose(yyout)==EOF){
    perror("Erreur fclose() dans main()");
  }
  return 0;
}
