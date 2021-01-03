%{
    #include <stdio.h>
    #include "yacc_util.h"
    #include "errors.h"
    #include "symbol_table.h"
    #include "context.h"

    void yyerror (char *s);
    int yylex();
%}

%union {
    size_t nquad;
    int intval;
    char* strval;
    quadop quadop;
    type_e type;

    struct typedesc typedesc;

    struct typelist typelist;

    arrind *arrind;

    identifierlist *identifierlist;

    struct expr_s expression;

    struct {
      quadop quadop;
      liste *next;
    } instruction;

    struct {
      quadop quadop;
      int tab;
    } lval;

    struct{
        int nb_dim;
        interval_list* range;
    } rangeval;

    struct{
        int nb_dim; //nbr de dimension
        interval_list* range; //intervales pour chaque dimension
        type_e valtype; //type des valeurs dans l'array
    } arrayval;
}

%start program

/* liste des terminaux */
%token <intval> NOMBRE INTG
%token <strval> IDENT STR
%token FUNCTION
%token PLUS MOINS FOIS DIV UMOINS
%token VAR
%token BOOL INT UNIT STRING
%token ARRAY
%token SEP TWO_POINT COMMA SEPIND
%token WHILE DO
%token IF THEN
%token ELSE
%token OF
%token XOR OR AND NOT
%token SUP SUPEQ INF INFEQ EQ
%token TRUE FALSE
%token OPAR CPAR
%token AFFECT
%token BEG END
%token WRITE READ
%token PROGRAM

%type <type> atomic_type par
%type <typedesc> parlist
%type <typelist> exprlist
%type <arrind> indexlist
%type <identifierlist> identlist

%type <quadop> lvalue
%type <nquad> m n
%type <instruction> instr sequence g
%type <expression> expr cte
%type <rangeval> rangelist
%type <arrayval> arraytype
%type <intval> integer

%left XOR OR
%left PLUS MOINS
%left AND
%left FOIS DIV
%right POW
%right NOT
%right UMOINS
%left SUP SUPEQ INF INFEQ EQ DIFF
%left IF THEN
%left ELSE

%%

program:
    PROGRAM IDENT vardecllist funcdeclist instr
    {
    	complete($5.next, current_context->nextquad);
    }
;

funcdeclist: /*empty*/ | funcdecl SEP funcdeclist;

funcdecl:
    FUNCTION IDENT { newname($2); pushcontext($2); } OPAR parlist
    CPAR TWO_POINT atomic_type
    vardecllist
    instr
    {
        popcontext();

        entry *e = lookup($2);
        e->typedesc = $5;
        e->typedesc.returntype = $8;
        e->typedesc.type = TYPE_FUNC;
    }
;

parlist:
    /*empty*/ {}
    | par
    {
       $$.params[$$.nb_params] = $1;
       $$.nb_params++;
    }
    | par COMMA parlist
    {
       $3.params[$3.nb_params] = $1;
       $3.nb_params++;

       $$ = $3;
    }
;

par:
    IDENT TWO_POINT atomic_type
    {
       entry *e = newname($1);
       e->typedesc.type = $3;

       $$ = $3;
    }
;

vardecllist: /*empty*/ | varsdecl | varsdecl SEP vardecllist

varsdecl:
    VAR identlist TWO_POINT atomic_type
    {
        identifierlist *copy = $2;
        entry *e;

        while (copy != NULL)
        {
            e = lookup(copy->name);
            if (e == NULL)
                lookup_error(copy->name);

            e->typedesc.type = $4;
            copy = copy->next;
        }
    }
    | VAR identlist TWO_POINT arraytype
    {
        identifierlist *copy = $2;
        entry *e;

        while (copy != NULL)
        {
            e = lookup(copy->name);
            if (e == NULL)
                lookup_error(copy->name);

            e->typedesc.type = TYPE_ARRAY;
            e->nb_dim = $4.nb_dim;
            e->rangelist = $4.range;
            e->valtype = $4.valtype;
            copy = copy->next;
        }
    }
;

identlist:
    IDENT
    {
       newname($1);
       $$ = creeidentlist($1);
    }
    | IDENT COMMA identlist
    {
       newname($1);
       $$ = concatidentlist($3, creeidentlist($1));
    }


atomic_type:
      UNIT   {$$ = TYPE_UNIT;}
    | BOOL   {$$ = TYPE_BOOL;}
    | INT    {$$ = TYPE_INT;}
    | STRING {$$ = TYPE_STRING;}
;

arraytype:
    ARRAY '[' rangelist ']' OF atomic_type
    {
        $$.nb_dim = $3.nb_dim;
        $$.range = $3.range;
        $$.valtype = $6;   
    }
;

rangelist:
      integer SEPIND integer 
      {
          $$.nb_dim = 1;
          $$.range = cree_interval($1,$3);
      }
    | rangelist COMMA integer SEPIND integer 
      {
          interval_list* newi;
          newi = cree_interval($3,$5);

          $$.nb_dim = 1 + $1.nb_dim;
          $$.range = concat_interval($1.range, newi);
      }
;

integer:
      NOMBRE        {$$ = $1;}
    |  MOINS NOMBRE {$$ = -$2;}
;

instr:
    lvalue AFFECT expr
    {
        if (lookup($1.u.name) == NULL)
	        lookup_error($1.u.name);

        quad q;
        if ($1.for_tab == 1)
        {
            q = quad_make(Q_SAVE_ELEM_ARR, $1, emp, $3.quadop, current_context->nextquad);
        }
        else
        {
            q = quad_make(Q_AFFECT, $3.quadop, emp, $1, current_context->nextquad);
        }

        gencode(q);
    }
  | WHILE m expr DO m instr
    {
        complete($3.true, $5);
        complete($6.next, $2);
        $$.next = $3.false;
        quad q = quad_make(Q_GOTO, emp, emp, quadop_etiquette($2), current_context->nextquad);
        gencode(q);
    }
  | IF expr THEN m instr
    {
        complete($2.true, $4);
        $$.next = concat($2.false, $5.next);
    }
  | IF expr THEN m instr ELSE g m instr
    {
        complete($2.true, $4);
        complete($2.false, $8);
        $$.next = concat3($5.next, $7.next, $9.next);
    }
  | IDENT OPAR exprlist CPAR
    {
        entry *e = lookup($1);
        if (e == NULL)
           lookup_error($1);

        check_function_type(e->typedesc, $3);

        quadop t = newtemp();
        lookup(t.u.name)->typedesc.type = e->typedesc.returntype;

        quad q = quad_make(Q_CALL, quadop_name($1), quadop_cst($3.nb_types), t, current_context->nextquad);
        gencode(q);
        $$.quadop = t;
    }
  | BEG sequence END
    {
        $$.next = $2.next;
    }
  | BEG END {;}
  | WRITE expr
    {
        quad q = quad_make(Q_WRITE, emp, emp, $2.quadop, current_context->nextquad);
        gencode(q);
    }
  | READ lvalue
    {
        if (lookup($2.u.name) == NULL)
	        lookup_error($2.u.name);
        
        quad q = quad_make(Q_READ, emp, emp, $2, current_context->nextquad);
        gencode(q);
    }
;

sequence:
    instr SEP m sequence
    {
         complete($1.next, $3);
         $$.next = $4.next;
    }
  | instr SEP
    {
         complete($1.next, current_context->nextquad);
    }
  | instr
    {
    	$$.next = $1.next;
    }
;

lvalue:
    IDENT
    {
        $$ = quadop_name($1);
    }
    | IDENT '[' indexlist ']'
    {
        struct expr_s tmp = array_expr($1, Q_SAVE_ELEM_ARR, $3);
        $$ = tmp.quadop;
    }
;

exprlist:
    expr
    {
       quad q = quad_make(Q_PARAM, $1.quadop, emp, emp, current_context->nextquad);
       gencode(q);

       $$.typelist[$$.nb_types] = $1.typedesc;
       $$.nb_types++;

       arrind* a= cree_arrind($1.quadop); 
       $$.array_indexes= a;
    }
    | expr COMMA exprlist
    {
        quad q = quad_make(Q_PARAM, $1.quadop, emp, emp, current_context->nextquad);
        gencode(q);

        $3.typelist[$3.nb_types] = $1.typedesc;
        $3.nb_types++;

        arrind* a = cree_arrind($1.quadop);
        $$.array_indexes = concat_arrind(a, $3.array_indexes);

        $$ = $3;
    }
;

indexlist:
    expr
    {
        $$ = cree_arrind($1.quadop);
    }
    | expr COMMA indexlist
    {
        arrind* a = cree_arrind($1.quadop);
        $$ = concat_arrind(a, $3);
    }

expr:
    OPAR expr CPAR  { $$ = $2; }
  | expr PLUS expr  { $$ = arithmetique_expr($1, Q_PLUS, $3); }
  | expr MOINS expr { $$ = arithmetique_expr($1, Q_MOINS, $3); }
  | expr FOIS expr  { $$ = arithmetique_expr($1, Q_FOIS, $3); }
  | expr DIV expr   { $$ = arithmetique_expr($1, Q_DIV, $3); }
  | expr POW expr   { $$ = arithmetique_expr($1, Q_POW, $3); }
  | expr SUP expr   { $$ = bool_expr($1, Q_SUP, $3); }
  | expr SUPEQ expr { $$ = bool_expr($1, Q_SUPEQ, $3); }
  | expr INF expr   { $$ = bool_expr($1, Q_INF, $3); }
  | expr INFEQ expr { $$ = bool_expr($1, Q_INFEQ, $3); }
  | expr EQ expr    { $$ = bool_expr($1, Q_EQ, $3); }
  | expr DIFF expr  { $$ = bool_expr($1, Q_DIFF, $3); }
  | MOINS expr       %prec UMOINS  
  {
     struct expr_s zer;
     zer.quadop = quadop_cst(0);
     zer.typedesc.type = TYPE_INT;
     $$ = arithmetique_expr(zer, Q_MOINS, $2); 
  }
  | expr OR m expr
  {
     $$.true = concat($1.true, $4.true);
     complete($1.false, $3);
     $$.false = $4.false;
  }
  | expr XOR n expr
  {
      quad q;
      complete($1.true, $3);
      complete($1.false, $3 + 2);

      complete($4.true, current_context->nextquad);
      $$.true = creelist(current_context->nextquad);
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(0), emp, current_context->nextquad);
      gencode(q);

      $$.false = creelist(current_context->nextquad);
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(1), emp, current_context->nextquad);
      gencode(q);

      complete($4.false, current_context->nextquad);
      $$.true = concat($$.true, creelist(current_context->nextquad));
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(1), emp, current_context->nextquad);
      gencode(q);

      $$.false = concat($$.false, creelist(current_context->nextquad));
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(0), emp, current_context->nextquad);
      gencode(q);
  }
  | expr AND m expr
  {
     $$.true = $4.true;
     complete($1.true, $3);
     $$.false = concat($1.false, $4.false);
  }
  | NOT expr
  {
     $$.true = $2.false;
     $$.false = $2.true;
  }
  | IDENT OPAR exprlist CPAR
    {
        entry *e = lookup($1);
        if (e == NULL)
           lookup_error($1);

        check_function_type(e->typedesc, $3);

        quadop t = newtemp();
        lookup(t.u.name)->typedesc.type = e->typedesc.returntype;

        quad q = quad_make(Q_CALL, quadop_name($1), quadop_cst($3.nb_types), t, current_context->nextquad);
        gencode(q);
        $$.quadop = t;
        $$.typedesc.type = e->typedesc.returntype;
    }
  | IDENT '[' indexlist ']'
  {
        $$ = array_expr($1, Q_ACCESS_ELEM_ARR, $3);
  }
  | cte
    {
        $$.quadop = $1.quadop;
        $$.typedesc.type = $1.typedesc.type;
    }
;

cte: NOMBRE
    {
        $$.quadop = quadop_cst($1);
        $$.typedesc.type = TYPE_INT;
    }
    | STR
    {
        $$.quadop = quadop_str($1);
        $$.typedesc.type = TYPE_STRING;
    }
    | IDENT
    {
	entry *e = lookup($1);

	if (e == NULL)
	   lookup_error($1);

	$$.typedesc = e->typedesc;
        $$.quadop = quadop_name($1);
    }
    | TRUE
    {
        $$.quadop = quadop_bool(1);
        $$.typedesc.type = TYPE_BOOL;
    }
    | FALSE
    {
        $$.quadop = quadop_bool(0);
        $$.typedesc.type = TYPE_BOOL;
    }
;

g: /* empty */ {
     $$.next = creelist(current_context->nextquad);
     quad q = quad_make(Q_GOTO, emp, emp, emp, current_context->nextquad);
     gencode(q);
   }
;

m: /* empty */ { $$ = current_context->nextquad; };

n: /* empty */ 
{
    $$ = current_context->nextquad;

    quad q = quad_make(Q_AFFECT, quadop_cst(1), emp, quadop_name("varXOR"), current_context->nextquad);
    gencode(q);
    q = quad_make(Q_GOTO, emp, emp, quadop_cst(current_context->nextquad+2), current_context->nextquad);
    gencode(q);
    q = quad_make(Q_AFFECT, quadop_cst(0), emp, quadop_name("varXOR"), current_context->nextquad);
    gencode(q);
};

%%

void yyerror (char *s) {fprintf (stderr, "%s\n", s);}

