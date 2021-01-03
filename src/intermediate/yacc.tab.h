/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NOMBRE = 258,
    INTG = 259,
    IDENT = 260,
    STR = 261,
    FUNCTION = 262,
    PLUS = 263,
    MOINS = 264,
    FOIS = 265,
    DIV = 266,
    UMOINS = 267,
    VAR = 268,
    BOOL = 269,
    INT = 270,
    UNIT = 271,
    STRING = 272,
    ARRAY = 273,
    SEP = 274,
    TWO_POINT = 275,
    COMMA = 276,
    SEPIND = 277,
    WHILE = 278,
    DO = 279,
    IF = 280,
    THEN = 281,
    ELSE = 282,
    OF = 283,
    XOR = 284,
    OR = 285,
    AND = 286,
    NOT = 287,
    SUP = 288,
    SUPEQ = 289,
    INF = 290,
    INFEQ = 291,
    EQ = 292,
    TRUE = 293,
    FALSE = 294,
    OPAR = 295,
    CPAR = 296,
    AFFECT = 297,
    BEG = 298,
    END = 299,
    WRITE = 300,
    READ = 301,
    PROGRAM = 302,
    POW = 303,
    DIFF = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "src/intermediate/yacc.y" /* yacc.c:1909  */

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

#line 143 "yacc.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
