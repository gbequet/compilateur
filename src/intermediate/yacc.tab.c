/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/intermediate/yacc.y" /* yacc.c:339  */

    #include <stdio.h>
    #include "yacc_util.h"
    #include "errors.h"
    #include "symbol_table.h"
    #include "context.h"

    void yyerror (char *s);
    int yylex();

#line 77 "yacc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc.tab.h".  */
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
#line 12 "src/intermediate/yacc.y" /* yacc.c:355  */

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

#line 206 "yacc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "yacc.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   109,   109,   112,   112,   127,   128,   133,
     143,   152,   152,   152,   155,   170,   191,   196,   204,   205,
     206,   207,   211,   220,   225,   236,   237,   241,   258,   266,
     271,   277,   292,   296,   297,   302,   313,   318,   322,   329,
     333,   341,   352,   368,   372,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   398,   404,
     428,   434,   439,   455,   459,   466,   471,   476,   486,   491,
     498,   505,   508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOMBRE", "INTG", "IDENT", "STR",
  "FUNCTION", "PLUS", "MOINS", "FOIS", "DIV", "UMOINS", "VAR", "BOOL",
  "INT", "UNIT", "STRING", "ARRAY", "SEP", "TWO_POINT", "COMMA", "SEPIND",
  "WHILE", "DO", "IF", "THEN", "ELSE", "OF", "XOR", "OR", "AND", "NOT",
  "SUP", "SUPEQ", "INF", "INFEQ", "EQ", "TRUE", "FALSE", "OPAR", "CPAR",
  "AFFECT", "BEG", "END", "WRITE", "READ", "PROGRAM", "POW", "DIFF", "'['",
  "']'", "$accept", "program", "funcdeclist", "funcdecl", "$@1", "parlist",
  "par", "vardecllist", "varsdecl", "identlist", "atomic_type",
  "arraytype", "rangelist", "integer", "instr", "sequence", "lvalue",
  "exprlist", "indexlist", "expr", "cte", "g", "m", "n", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      91,    93
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,    14,    32,    21,  -107,    30,    38,    18,    29,    19,
      42,   185,    49,    21,    30,   177,  -107,   -28,  -107,     4,
      26,     4,    62,  -107,    31,    38,  -107,  -107,  -107,  -107,
    -107,  -107,    25,  -107,  -107,    53,     4,     4,     4,  -107,
     -23,  -107,     4,     4,  -107,  -107,     4,    48,  -107,  -107,
      75,    66,   204,    56,  -107,     4,  -107,    15,   118,    83,
      78,    74,   110,   140,     4,     4,    68,    68,   170,     4,
       4,     4,     4,  -107,  -107,  -107,  -107,     4,     4,     4,
       4,     4,     4,     4,    84,  -107,   204,  -107,   129,   -10,
     112,   115,    95,   121,  -107,     4,  -107,     4,  -107,   116,
     114,  -107,   240,   240,   149,   149,   185,     4,     4,     4,
    -107,  -107,  -107,  -107,  -107,   149,  -107,   185,  -107,    15,
     138,    15,   146,   152,   118,  -107,  -107,   185,  -107,  -107,
     160,   212,   212,   119,  -107,   174,   146,  -107,  -107,   146,
    -107,  -107,  -107,    15,  -107,    21,  -107,  -107,   185,   185,
    -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    11,     1,     0,     3,    12,    16,     0,
       0,     0,     0,    11,     0,     0,     5,    39,    71,     0,
       0,     0,     0,     2,     0,     3,    13,    17,    19,    20,
      18,    21,     0,    14,    15,     0,     0,     0,     0,    65,
      67,    66,     0,     0,    68,    69,     0,     0,    64,    33,
      38,     0,    34,    39,    35,     0,     4,     0,     7,     0,
      41,     0,    43,     0,     0,     0,    57,    61,     0,     0,
       0,     0,     0,    71,    72,    71,    71,     0,     0,     0,
       0,     0,     0,     0,    71,    32,    27,    25,     0,     0,
       0,     0,     0,     8,    31,     0,    40,     0,    71,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,     0,
      51,    52,    53,    54,    55,    50,    56,     0,    26,     0,
       0,     0,     0,     0,     7,    42,    44,     0,    62,    63,
      29,    59,    58,    60,    36,     0,     0,    23,    10,     0,
       9,    28,    70,     0,    22,    11,    71,    24,     0,     0,
       6,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   184,  -107,  -107,    92,  -107,   -12,  -107,   188,
    -106,  -107,  -107,   -21,   -11,   100,   202,   -49,   -57,   -17,
    -107,  -107,   -70,  -107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    12,    35,    92,    93,     6,     7,     9,
      33,    34,    89,    90,    50,    51,    24,    59,    61,    60,
      48,   146,    38,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    26,    47,   106,    52,   108,   109,    39,   100,    40,
      41,   119,    36,    42,   117,    99,   138,    64,    87,     3,
      62,    63,    37,     1,    88,    66,    67,    65,   127,    68,
     144,    17,     4,   145,     5,     8,    43,    13,    86,    15,
     126,   120,    44,    45,    46,    10,   125,    16,    62,    18,
      14,    19,   102,   103,   104,   105,    69,    70,    71,    72,
     110,   111,   112,   113,   114,   115,   116,    53,    25,    20,
      49,    21,    22,    55,    73,    57,   149,    74,    75,    76,
      62,    77,    78,    79,    80,    81,    69,    70,    71,    72,
     131,   132,   133,    58,    84,   130,    82,    83,   135,    95,
     137,    77,    78,    79,    80,    81,    37,    74,    75,    76,
      85,    77,    78,    79,    80,    81,   141,    83,    69,    70,
      71,    72,   147,    91,    94,    96,    82,    83,   -37,    71,
      72,    97,   118,   148,   121,   122,   123,   150,   151,    74,
      75,    76,   124,    77,    78,    79,    80,    81,    69,    70,
      71,    72,    77,    78,    79,    80,    81,   128,    82,    83,
      28,    29,    30,    31,    98,   129,   136,    82,    83,    74,
      75,    76,   139,    77,    78,    79,    80,    81,    69,    70,
      71,    72,    77,    78,    79,    80,    81,   142,    82,    83,
      17,    28,    29,    30,    31,    32,   143,    82,    83,    74,
      75,    76,    27,    77,    78,    79,    80,    81,    18,    56,
      19,   101,    69,    70,    71,    72,   140,   134,    82,    83,
      69,    70,    71,    72,    54,     0,     0,     0,    20,     0,
      21,    22,     0,    74,    75,    76,     0,    77,    78,    79,
      80,    81,     0,    76,     0,    77,    78,    79,    80,    81,
      71,    72,    82,    83,     0,     0,     0,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
      11,    13,    19,    73,    21,    75,    76,     3,    65,     5,
       6,    21,    40,     9,    84,    64,   122,    40,     3,     5,
      37,    38,    50,    47,     9,    42,    43,    50,    98,    46,
     136,     5,     0,   139,    13,     5,    32,    19,    55,    20,
      97,    51,    38,    39,    40,     7,    95,     5,    65,    23,
      21,    25,    69,    70,    71,    72,     8,     9,    10,    11,
      77,    78,    79,    80,    81,    82,    83,     5,    19,    43,
      44,    45,    46,    42,    26,    50,   146,    29,    30,    31,
      97,    33,    34,    35,    36,    37,     8,     9,    10,    11,
     107,   108,   109,    40,    19,   106,    48,    49,   119,    21,
     121,    33,    34,    35,    36,    37,    50,    29,    30,    31,
      44,    33,    34,    35,    36,    37,   127,    49,     8,     9,
      10,    11,   143,     5,    41,    51,    48,    49,    44,    10,
      11,    21,     3,   145,    22,    20,    41,   148,   149,    29,
      30,    31,    21,    33,    34,    35,    36,    37,     8,     9,
      10,    11,    33,    34,    35,    36,    37,    41,    48,    49,
      14,    15,    16,    17,    24,    51,    28,    48,    49,    29,
      30,    31,    20,    33,    34,    35,    36,    37,     8,     9,
      10,    11,    33,    34,    35,    36,    37,    27,    48,    49,
       5,    14,    15,    16,    17,    18,    22,    48,    49,    29,
      30,    31,    14,    33,    34,    35,    36,    37,    23,    25,
      25,    41,     8,     9,    10,    11,   124,   117,    48,    49,
       8,     9,    10,    11,    22,    -1,    -1,    -1,    43,    -1,
      45,    46,    -1,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    -1,    31,    -1,    33,    34,    35,    36,    37,
      10,    11,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    53,     5,     0,    13,    59,    60,     5,    61,
       7,    54,    55,    19,    21,    20,     5,     5,    23,    25,
      43,    45,    46,    66,    68,    19,    59,    61,    14,    15,
      16,    17,    18,    62,    63,    56,    40,    50,    74,     3,
       5,     6,     9,    32,    38,    39,    40,    71,    72,    44,
      66,    67,    71,     5,    68,    42,    54,    50,    40,    69,
      71,    70,    71,    71,    40,    50,    71,    71,    71,     8,
       9,    10,    11,    26,    29,    30,    31,    33,    34,    35,
      36,    37,    48,    49,    19,    44,    71,     3,     9,    64,
      65,     5,    57,    58,    41,    21,    51,    21,    24,    69,
      70,    41,    71,    71,    71,    71,    74,    75,    74,    74,
      71,    71,    71,    71,    71,    71,    71,    74,     3,    21,
      51,    22,    20,    41,    21,    69,    70,    74,    41,    51,
      66,    71,    71,    71,    67,    65,    28,    65,    62,    20,
      57,    66,    27,    22,    62,    62,    73,    65,    59,    74,
      66,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    56,    55,    57,    57,    57,
      58,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      73,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     3,     0,    10,     0,     1,     3,
       3,     0,     1,     3,     4,     4,     1,     3,     1,     1,
       1,     1,     6,     3,     5,     1,     2,     3,     6,     5,
       9,     4,     3,     2,     2,     2,     4,     2,     1,     1,
       4,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     4,     4,
       4,     2,     4,     4,     1,     1,     1,     1,     1,     1,
       0,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 104 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
    	complete((yyvsp[0].instruction).next, current_context->nextquad);
    }
#line 1434 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { newname((yyvsp[0].strval)); pushcontext((yyvsp[0].strval)); }
#line 1440 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        popcontext();

        entry *e = lookup((yyvsp[-8].strval));
        e->typedesc = (yyvsp[-5].typedesc);
        e->typedesc.returntype = (yyvsp[-2].type);
        e->typedesc.type = TYPE_FUNC;
    }
#line 1453 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {}
#line 1459 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
       (yyval.typedesc).params[(yyval.typedesc).nb_params] = (yyvsp[0].type);
       (yyval.typedesc).nb_params++;
    }
#line 1468 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
       (yyvsp[0].typedesc).params[(yyvsp[0].typedesc).nb_params] = (yyvsp[-2].type);
       (yyvsp[0].typedesc).nb_params++;

       (yyval.typedesc) = (yyvsp[0].typedesc);
    }
#line 1479 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
       entry *e = newname((yyvsp[-2].strval));
       e->typedesc.type = (yyvsp[0].type);

       (yyval.type) = (yyvsp[0].type);
    }
#line 1490 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 156 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        identifierlist *copy = (yyvsp[-2].identifierlist);
        entry *e;

        while (copy != NULL)
        {
            e = lookup(copy->name);
            if (e == NULL)
                lookup_error(copy->name);

            e->typedesc.type = (yyvsp[0].type);
            copy = copy->next;
        }
    }
#line 1509 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 171 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        identifierlist *copy = (yyvsp[-2].identifierlist);
        entry *e;

        while (copy != NULL)
        {
            e = lookup(copy->name);
            if (e == NULL)
                lookup_error(copy->name);

            e->typedesc.type = TYPE_ARRAY;
            e->nb_dim = (yyvsp[0].arrayval).nb_dim;
            e->rangelist = (yyvsp[0].arrayval).range;
            e->valtype = (yyvsp[0].arrayval).valtype;
            copy = copy->next;
        }
    }
#line 1531 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 192 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
       newname((yyvsp[0].strval));
       (yyval.identifierlist) = creeidentlist((yyvsp[0].strval));
    }
#line 1540 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 197 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
       newname((yyvsp[-2].strval));
       (yyval.identifierlist) = concatidentlist((yyvsp[0].identifierlist), creeidentlist((yyvsp[-2].strval)));
    }
#line 1549 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {(yyval.type) = TYPE_UNIT;}
#line 1555 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 205 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {(yyval.type) = TYPE_BOOL;}
#line 1561 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 206 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {(yyval.type) = TYPE_INT;}
#line 1567 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 207 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {(yyval.type) = TYPE_STRING;}
#line 1573 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 212 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.arrayval).nb_dim = (yyvsp[-3].rangeval).nb_dim;
        (yyval.arrayval).range = (yyvsp[-3].rangeval).range;
        (yyval.arrayval).valtype = (yyvsp[0].type);   
    }
#line 1583 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 221 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
          (yyval.rangeval).nb_dim = 1;
          (yyval.rangeval).range = cree_interval((yyvsp[-2].intval),(yyvsp[0].intval));
      }
#line 1592 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 226 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
          interval_list* newi;
          newi = cree_interval((yyvsp[-2].intval),(yyvsp[0].intval));

          (yyval.rangeval).nb_dim = 1 + (yyvsp[-4].rangeval).nb_dim;
          (yyval.rangeval).range = concat_interval((yyvsp[-4].rangeval).range, newi);
      }
#line 1604 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1610 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 237 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {(yyval.intval) = -(yyvsp[0].intval);}
#line 1616 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 242 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        if (lookup((yyvsp[-2].quadop).u.name) == NULL)
	        lookup_error((yyvsp[-2].quadop).u.name);

        quad q;
        if ((yyvsp[-2].quadop).for_tab == 1)
        {
            q = quad_make(Q_SAVE_ELEM_ARR, (yyvsp[-2].quadop), emp, (yyvsp[0].expression).quadop, current_context->nextquad);
        }
        else
        {
            q = quad_make(Q_AFFECT, (yyvsp[0].expression).quadop, emp, (yyvsp[-2].quadop), current_context->nextquad);
        }

        gencode(q);
    }
#line 1637 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 259 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        complete((yyvsp[-3].expression).true, (yyvsp[-1].nquad));
        complete((yyvsp[0].instruction).next, (yyvsp[-4].nquad));
        (yyval.instruction).next = (yyvsp[-3].expression).false;
        quad q = quad_make(Q_GOTO, emp, emp, quadop_etiquette((yyvsp[-4].nquad)), current_context->nextquad);
        gencode(q);
    }
#line 1649 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 267 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        complete((yyvsp[-3].expression).true, (yyvsp[-1].nquad));
        (yyval.instruction).next = concat((yyvsp[-3].expression).false, (yyvsp[0].instruction).next);
    }
#line 1658 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 272 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        complete((yyvsp[-7].expression).true, (yyvsp[-5].nquad));
        complete((yyvsp[-7].expression).false, (yyvsp[-1].nquad));
        (yyval.instruction).next = concat3((yyvsp[-4].instruction).next, (yyvsp[-2].instruction).next, (yyvsp[0].instruction).next);
    }
#line 1668 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 278 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        entry *e = lookup((yyvsp[-3].strval));
        if (e == NULL)
           lookup_error((yyvsp[-3].strval));

        check_function_type(e->typedesc, (yyvsp[-1].typelist));

        quadop t = newtemp();
        lookup(t.u.name)->typedesc.type = e->typedesc.returntype;

        quad q = quad_make(Q_CALL, quadop_name((yyvsp[-3].strval)), quadop_cst((yyvsp[-1].typelist).nb_types), t, current_context->nextquad);
        gencode(q);
        (yyval.instruction).quadop = t;
    }
#line 1687 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 293 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.instruction).next = (yyvsp[-1].instruction).next;
    }
#line 1695 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 296 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {;}
#line 1701 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 298 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        quad q = quad_make(Q_WRITE, emp, emp, (yyvsp[0].expression).quadop, current_context->nextquad);
        gencode(q);
    }
#line 1710 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 303 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        if (lookup((yyvsp[0].quadop).u.name) == NULL)
	        lookup_error((yyvsp[0].quadop).u.name);
        
        quad q = quad_make(Q_READ, emp, emp, (yyvsp[0].quadop), current_context->nextquad);
        gencode(q);
    }
#line 1722 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 314 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
         complete((yyvsp[-3].instruction).next, (yyvsp[-1].nquad));
         (yyval.instruction).next = (yyvsp[0].instruction).next;
    }
#line 1731 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 319 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
         complete((yyvsp[-1].instruction).next, current_context->nextquad);
    }
#line 1739 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 323 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
    	(yyval.instruction).next = (yyvsp[0].instruction).next;
    }
#line 1747 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 330 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.quadop) = quadop_name((yyvsp[0].strval));
    }
#line 1755 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 334 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        struct expr_s tmp = array_expr((yyvsp[-3].strval), Q_SAVE_ELEM_ARR, (yyvsp[-1].arrind));
        (yyval.quadop) = tmp.quadop;
    }
#line 1764 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 342 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
       quad q = quad_make(Q_PARAM, (yyvsp[0].expression).quadop, emp, emp, current_context->nextquad);
       gencode(q);

       (yyval.typelist).typelist[(yyval.typelist).nb_types] = (yyvsp[0].expression).typedesc;
       (yyval.typelist).nb_types++;

       arrind* a= cree_arrind((yyvsp[0].expression).quadop); 
       (yyval.typelist).array_indexes= a;
    }
#line 1779 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 353 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        quad q = quad_make(Q_PARAM, (yyvsp[-2].expression).quadop, emp, emp, current_context->nextquad);
        gencode(q);

        (yyvsp[0].typelist).typelist[(yyvsp[0].typelist).nb_types] = (yyvsp[-2].expression).typedesc;
        (yyvsp[0].typelist).nb_types++;

        arrind* a = cree_arrind((yyvsp[-2].expression).quadop);
        (yyval.typelist).array_indexes = concat_arrind(a, (yyvsp[0].typelist).array_indexes);

        (yyval.typelist) = (yyvsp[0].typelist);
    }
#line 1796 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 369 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.arrind) = cree_arrind((yyvsp[0].expression).quadop);
    }
#line 1804 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 373 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        arrind* a = cree_arrind((yyvsp[-2].expression).quadop);
        (yyval.arrind) = concat_arrind(a, (yyvsp[0].arrind));
    }
#line 1813 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 379 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1819 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 380 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = arithmetique_expr((yyvsp[-2].expression), Q_PLUS, (yyvsp[0].expression)); }
#line 1825 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 381 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = arithmetique_expr((yyvsp[-2].expression), Q_MOINS, (yyvsp[0].expression)); }
#line 1831 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 382 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = arithmetique_expr((yyvsp[-2].expression), Q_FOIS, (yyvsp[0].expression)); }
#line 1837 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 383 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = arithmetique_expr((yyvsp[-2].expression), Q_DIV, (yyvsp[0].expression)); }
#line 1843 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 384 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = arithmetique_expr((yyvsp[-2].expression), Q_POW, (yyvsp[0].expression)); }
#line 1849 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 385 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_expr((yyvsp[-2].expression), Q_SUP, (yyvsp[0].expression)); }
#line 1855 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 386 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_expr((yyvsp[-2].expression), Q_SUPEQ, (yyvsp[0].expression)); }
#line 1861 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 387 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_expr((yyvsp[-2].expression), Q_INF, (yyvsp[0].expression)); }
#line 1867 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 388 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_expr((yyvsp[-2].expression), Q_INFEQ, (yyvsp[0].expression)); }
#line 1873 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_expr((yyvsp[-2].expression), Q_EQ, (yyvsp[0].expression)); }
#line 1879 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 390 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_expr((yyvsp[-2].expression), Q_DIFF, (yyvsp[0].expression)); }
#line 1885 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 392 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
     struct expr_s zer;
     zer.quadop = quadop_cst(0);
     zer.typedesc.type = TYPE_INT;
     (yyval.expression) = arithmetique_expr(zer, Q_MOINS, (yyvsp[0].expression)); 
  }
#line 1896 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 399 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
     (yyval.expression).true = concat((yyvsp[-3].expression).true, (yyvsp[0].expression).true);
     complete((yyvsp[-3].expression).false, (yyvsp[-1].nquad));
     (yyval.expression).false = (yyvsp[0].expression).false;
  }
#line 1906 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 405 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
      quad q;
      complete((yyvsp[-3].expression).true, (yyvsp[-1].nquad));
      complete((yyvsp[-3].expression).false, (yyvsp[-1].nquad) + 2);

      complete((yyvsp[0].expression).true, current_context->nextquad);
      (yyval.expression).true = creelist(current_context->nextquad);
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(0), emp, current_context->nextquad);
      gencode(q);

      (yyval.expression).false = creelist(current_context->nextquad);
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(1), emp, current_context->nextquad);
      gencode(q);

      complete((yyvsp[0].expression).false, current_context->nextquad);
      (yyval.expression).true = concat((yyval.expression).true, creelist(current_context->nextquad));
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(1), emp, current_context->nextquad);
      gencode(q);

      (yyval.expression).false = concat((yyval.expression).false, creelist(current_context->nextquad));
      q = quad_make(Q_EQ, quadop_name("varXOR"), quadop_cst(0), emp, current_context->nextquad);
      gencode(q);
  }
#line 1934 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 429 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
     (yyval.expression).true = (yyvsp[0].expression).true;
     complete((yyvsp[-3].expression).true, (yyvsp[-1].nquad));
     (yyval.expression).false = concat((yyvsp[-3].expression).false, (yyvsp[0].expression).false);
  }
#line 1944 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 435 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
     (yyval.expression).true = (yyvsp[0].expression).false;
     (yyval.expression).false = (yyvsp[0].expression).true;
  }
#line 1953 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 440 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        entry *e = lookup((yyvsp[-3].strval));
        if (e == NULL)
           lookup_error((yyvsp[-3].strval));

        check_function_type(e->typedesc, (yyvsp[-1].typelist));

        quadop t = newtemp();
        lookup(t.u.name)->typedesc.type = e->typedesc.returntype;

        quad q = quad_make(Q_CALL, quadop_name((yyvsp[-3].strval)), quadop_cst((yyvsp[-1].typelist).nb_types), t, current_context->nextquad);
        gencode(q);
        (yyval.expression).quadop = t;
        (yyval.expression).typedesc.type = e->typedesc.returntype;
    }
#line 1973 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 456 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.expression) = array_expr((yyvsp[-3].strval), Q_ACCESS_ELEM_ARR, (yyvsp[-1].arrind));
  }
#line 1981 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 460 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.expression).quadop = (yyvsp[0].expression).quadop;
        (yyval.expression).typedesc.type = (yyvsp[0].expression).typedesc.type;
    }
#line 1990 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 467 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.expression).quadop = quadop_cst((yyvsp[0].intval));
        (yyval.expression).typedesc.type = TYPE_INT;
    }
#line 1999 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 472 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.expression).quadop = quadop_str((yyvsp[0].strval));
        (yyval.expression).typedesc.type = TYPE_STRING;
    }
#line 2008 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 477 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
	entry *e = lookup((yyvsp[0].strval));

	if (e == NULL)
	   lookup_error((yyvsp[0].strval));

	(yyval.expression).typedesc = e->typedesc;
        (yyval.expression).quadop = quadop_name((yyvsp[0].strval));
    }
#line 2022 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 487 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.expression).quadop = quadop_bool(1);
        (yyval.expression).typedesc.type = TYPE_BOOL;
    }
#line 2031 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 492 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
        (yyval.expression).quadop = quadop_bool(0);
        (yyval.expression).typedesc.type = TYPE_BOOL;
    }
#line 2040 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 498 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
     (yyval.instruction).next = creelist(current_context->nextquad);
     quad q = quad_make(Q_GOTO, emp, emp, emp, current_context->nextquad);
     gencode(q);
   }
#line 2050 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "src/intermediate/yacc.y" /* yacc.c:1646  */
    { (yyval.nquad) = current_context->nextquad; }
#line 2056 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 508 "src/intermediate/yacc.y" /* yacc.c:1646  */
    {
    (yyval.nquad) = current_context->nextquad;

    quad q = quad_make(Q_AFFECT, quadop_cst(1), emp, quadop_name("varXOR"), current_context->nextquad);
    gencode(q);
    q = quad_make(Q_GOTO, emp, emp, quadop_cst(current_context->nextquad+2), current_context->nextquad);
    gencode(q);
    q = quad_make(Q_AFFECT, quadop_cst(0), emp, quadop_name("varXOR"), current_context->nextquad);
    gencode(q);
}
#line 2071 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2075 "yacc.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 519 "src/intermediate/yacc.y" /* yacc.c:1906  */


void yyerror (char *s) {fprintf (stderr, "%s\n", s);}

