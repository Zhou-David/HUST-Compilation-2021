/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.y" /* yacc.c:339  */

        #include "stdio.h"
        #include "math.h"
        #include "string.h"
        #include "def.h"
        extern int yylineno;
        extern char *yytext;
        extern FILE *yyin;
        int yylex();
        void yyerror(const char* fmt, ...);
        void display(struct ASTNode *,int);
        void displayRoot();

#line 80 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


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
    CHAR = 258,
    STRING = 259,
    BOOL = 260,
    INT = 261,
    ID = 262,
    ERRORID = 263,
    RELOP = 264,
    TYPE = 265,
    FLOAT = 266,
    STRUCT = 267,
    RETURN = 268,
    FOR = 269,
    SWITCH = 270,
    CASE = 271,
    COLON = 272,
    DEFAULT = 273,
    STRUCT_VISIT = 274,
    STRUCT_NEW = 275,
    STRUCT_DEC = 276,
    EXT_STRUCT_DEC = 277,
    CASE_STMT = 278,
    CASE_STMT_LIST = 279,
    DEFAULT_STMT = 280,
    FOR_DEC = 281,
    FOR_EXP1 = 282,
    FOR_EXP2 = 283,
    FOR_EXP3 = 284,
    DPLUS = 285,
    LP = 286,
    RP = 287,
    LC = 288,
    RC = 289,
    LB = 290,
    RB = 291,
    SEMI = 292,
    COMMA = 293,
    DOT = 294,
    PLUS = 295,
    MINUS = 296,
    STAR = 297,
    DIV = 298,
    MOD = 299,
    ASSIGNOP = 300,
    PLUSASSIGNOP = 301,
    MINUSASSIGNOP = 302,
    STARASSIGNOP = 303,
    DIVASSIGNOP = 304,
    MODASSIGNOP = 305,
    AND = 306,
    OR = 307,
    NOT = 308,
    AUTOPLUS = 309,
    AUTOMINUS = 310,
    IF = 311,
    ELSE = 312,
    WHILE = 313,
    BREAK = 314,
    CONTINUE = 315,
    EXT_DEF_LIST = 316,
    EXT_VAR_DEF = 317,
    FUNC_DEF = 318,
    FUNC_DEC = 319,
    EXT_DEC_LIST = 320,
    PARAM_LIST = 321,
    PARAM_DEC = 322,
    VAR_DEF = 323,
    DEC_LIST = 324,
    DEF_LIST = 325,
    COMP_STM = 326,
    STM_LIST = 327,
    EXP_STMT = 328,
    IF_THEN = 329,
    IF_THEN_ELSE = 330,
    FUNC_CALL = 331,
    ARGS = 332,
    FUNCTION = 333,
    PARAM = 334,
    ARG = 335,
    CALL = 336,
    LABEL = 337,
    GOTO = 338,
    JLT = 339,
    JLE = 340,
    JGT = 341,
    JGE = 342,
    EQ = 343,
    NEQ = 344,
    ARRAY_LIST = 345,
    UMINUS = 346,
    DMINUS = 347,
    LOWER_THEN_ELSE = 348
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:355  */

	int type_int;
    char type_char;
	float type_float;
    char type_bool[5];
    char type_string[1024];
	char type_id[32];
	struct ASTNode *ptr;

#line 221 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);



/* Copy the second part of user declarations.  */

#line 250 "parser.tab.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   593

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    73,    74,    76,    77,    78,    79,    81,
      83,    84,    86,    87,    90,    91,    93,    94,    96,    97,
      99,   102,   104,   105,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   119,   123,   124,   129,   130,   131,
     143,   144,   145,   146,   147,   148,   149,   150,   153,   154,
     156,   158,   159,   164,   165,   167,   168,   171,   172,   173,
     175,   176,   178,   179,   181,   182,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   218,
     219,   221,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "STRING", "BOOL", "INT", "ID",
  "ERRORID", "RELOP", "TYPE", "FLOAT", "STRUCT", "RETURN", "FOR", "SWITCH",
  "CASE", "COLON", "DEFAULT", "STRUCT_VISIT", "STRUCT_NEW", "STRUCT_DEC",
  "EXT_STRUCT_DEC", "CASE_STMT", "CASE_STMT_LIST", "DEFAULT_STMT",
  "FOR_DEC", "FOR_EXP1", "FOR_EXP2", "FOR_EXP3", "DPLUS", "LP", "RP", "LC",
  "RC", "LB", "RB", "SEMI", "COMMA", "DOT", "PLUS", "MINUS", "STAR", "DIV",
  "MOD", "ASSIGNOP", "PLUSASSIGNOP", "MINUSASSIGNOP", "STARASSIGNOP",
  "DIVASSIGNOP", "MODASSIGNOP", "AND", "OR", "NOT", "AUTOPLUS",
  "AUTOMINUS", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "EXT_DEF_LIST",
  "EXT_VAR_DEF", "FUNC_DEF", "FUNC_DEC", "EXT_DEC_LIST", "PARAM_LIST",
  "PARAM_DEC", "VAR_DEF", "DEC_LIST", "DEF_LIST", "COMP_STM", "STM_LIST",
  "EXP_STMT", "IF_THEN", "IF_THEN_ELSE", "FUNC_CALL", "ARGS", "FUNCTION",
  "PARAM", "ARG", "CALL", "LABEL", "GOTO", "JLT", "JLE", "JGT", "JGE",
  "EQ", "NEQ", "ARRAY_LIST", "UMINUS", "DMINUS", "LOWER_THEN_ELSE",
  "$accept", "program", "ExtDefList", "ExtDef", "Specifier", "ExtDecList",
  "VarDec", "Arraylist", "FuncDec", "VarList", "ParamDec", "CompSt",
  "StmList", "Stmt", "DefaultStmt", "CaseStmt", "CaseStmtList", "ForDec",
  "ForExp1", "ForExp2", "ForExp3", "Struct_dec", "StructName", "DefList",
  "Def", "DecList", "Dec", "Exp_less", "Exp", "Args", YY_NULL
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      99,   -34,  -123,     7,    66,  -123,    99,    62,    45,  -123,
      76,    60,  -123,  -123,    33,    64,    68,    69,  -123,  -123,
      12,    13,    91,  -123,  -123,   106,    74,  -123,    79,   106,
      84,    88,    74,  -123,   106,    92,    85,    89,    96,  -123,
     132,  -123,    81,   103,   104,  -123,  -123,  -123,  -123,  -123,
     131,    96,  -123,  -123,  -123,  -123,    59,  -123,   217,   113,
     117,   217,   217,   217,   217,   217,   217,   118,   119,   120,
     121,  -123,   122,   132,  -123,   275,   217,  -123,   106,  -123,
    -123,   148,   256,  -123,   298,    -6,   217,   -12,   324,   -12,
     -12,   -12,   -12,   217,   217,  -123,  -123,  -123,  -123,   217,
    -123,  -123,   153,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,  -123,  -123,   477,  -123,
    -123,   350,   129,    89,   128,   477,  -123,   163,   106,   139,
     135,  -123,   376,  -123,   402,   428,   236,  -123,   538,   538,
      37,    37,    37,   503,   503,   503,   503,   503,   503,   210,
     521,   217,  -123,  -123,   217,   138,   477,  -123,   132,   202,
     143,   132,   132,  -123,  -123,   454,   217,  -123,   217,   140,
      56,   124,  -123,   217,  -123,  -123,   217,    38,   165,  -123,
      56,   149,   132,  -123,  -123,   167,   178,   132,  -123,  -123,
    -123,   132,   132,  -123,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     9,    55,     0,     2,     0,     0,     0,     8,
      56,     0,     1,     4,    12,     0,    10,     0,     7,    54,
       0,     0,     0,    13,     5,     0,     0,     6,     0,     0,
       0,     0,     0,    17,     0,     0,    18,     0,    12,    11,
      22,    59,    64,     0,    62,    61,    53,    58,    20,    16,
       0,    14,    92,    93,    95,   100,    91,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    22,    99,     0,     0,    60,     0,    19,
      15,     0,     0,    97,     0,     0,     0,    87,     0,    85,
      86,    82,    83,     0,     0,    31,    30,    21,    23,     0,
      88,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    65,    63,
      90,   102,     0,   100,    99,     0,    26,     0,     0,     0,
       0,    48,     0,    84,     0,     0,    74,    98,    75,    76,
      77,    78,    79,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    89,    96,    47,     0,    50,    49,     0,     0,
       0,     0,     0,   101,    46,    52,    45,    32,    43,     0,
      37,    27,    29,     0,    44,    41,    42,     0,     0,    39,
      37,     0,     0,    51,    40,     0,     0,    22,    38,    33,
      28,    22,    22,    34,    36,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,   190,  -123,    11,   172,     8,   -35,  -123,   160,
    -123,   181,   -73,  -122,  -123,  -123,    19,  -123,  -123,    52,
    -103,    28,  -123,     3,  -123,   -66,  -123,   130,   -56,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    29,    15,    42,    23,    17,    35,
      36,    71,    72,    73,   179,   180,   181,   129,   130,   155,
     164,    30,    11,    31,    32,    43,    44,    74,    75,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    38,    84,     9,     2,    87,    88,    89,    90,    91,
      92,     7,   119,    28,    10,    16,    80,     7,   100,   131,
     118,    83,     2,     2,     3,   121,   125,   102,     8,    40,
     132,   127,    34,    16,     8,    47,   167,   134,   135,   171,
     172,   185,    48,   136,   186,    33,   -57,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     190,    34,   157,   174,    21,   175,    12,   100,    22,    14,
     183,   156,   177,   184,   178,    28,   102,   -57,   -57,   -57,
     -57,   -57,    18,    19,     2,   -57,     3,   -57,   -57,   -57,
      81,   116,   117,    20,    82,   121,   128,    37,   165,    -3,
       1,    24,    26,   156,   -57,   -57,    25,   -57,   -57,     2,
     165,     3,   165,    38,   193,   -57,    41,   165,   194,   195,
     165,    45,    46,    50,    49,    51,    76,   -57,   -57,   -57,
     -57,    22,   -57,   -57,   -57,    52,    53,    54,    55,    56,
      77,     2,    78,    57,    85,    58,    59,    60,    86,    93,
      94,    52,    53,    54,    55,    56,    97,    95,    96,    57,
     137,   152,    61,    62,   153,    26,    52,    53,    54,    55,
      56,   158,   159,    63,    57,   166,   170,   176,    61,    62,
     120,   182,   187,   189,   191,    64,    65,    66,    67,    63,
      68,    69,    70,    61,    62,   192,    13,    39,    27,   188,
     154,    64,    65,    66,    63,    52,    53,    54,    55,    56,
      79,   169,   124,    57,   163,     0,    64,    65,    66,    99,
      52,    53,    54,    55,    56,     0,     0,     0,    57,     0,
       0,     0,    61,    62,     0,     0,     0,     0,     0,   168,
     100,     0,     0,    63,     0,     0,     0,    61,    62,   102,
     103,   104,   105,   106,   107,    64,    65,    66,    63,    52,
      53,    54,   123,    56,   116,   117,   100,    57,     0,     0,
      64,    65,    66,     0,     0,   102,   103,   104,   105,   106,
     107,     0,     0,     0,    99,     0,    61,    62,     0,     0,
     116,   117,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,   100,     0,    99,     0,    64,
      65,    66,   101,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   100,   116,
     117,     0,     0,    99,     0,   126,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   100,     0,   133,     0,     0,    99,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   117,
     100,     0,     0,     0,     0,    99,     0,     0,   151,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   100,     0,   160,     0,
       0,    99,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,   117,   100,     0,   161,     0,     0,    99,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,   117,   100,     0,
     162,     0,     0,    99,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   100,     0,    99,     0,     0,     0,
       0,     0,   173,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   100,   116,   117,
       0,     0,    99,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      99,   116,   117,   100,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,     0,     0,
       0,   100,     0,     0,   114,   115,     0,   116,   117,     0,
     102,   103,   104,   105,   106,   107,     0,     0,   100,     0,
       0,     0,   114,     0,     0,   116,   117,   102,     0,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,   117
};

static const yytype_int16 yycheck[] =
{
      73,     7,    58,    37,    10,    61,    62,    63,    64,    65,
      66,     0,    78,     1,     7,     7,    51,     6,    30,    85,
      76,    56,    10,    10,    12,    81,    82,    39,     0,    26,
      86,    37,    21,    25,     6,    32,   158,    93,    94,   161,
     162,     3,    34,    99,     6,    32,    34,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     182,    50,   128,   166,    31,   168,     0,    30,    35,     7,
     173,   127,    16,   176,    18,     1,    39,     3,     4,     5,
       6,     7,    37,     7,    10,    11,    12,    13,    14,    15,
      31,    54,    55,    33,    35,   151,    85,     6,   154,     0,
       1,    37,    33,   159,    30,    31,    38,    33,    34,    10,
     166,    12,   168,     7,   187,    41,    37,   173,   191,   192,
     176,    37,    34,    38,    32,    36,    45,    53,    54,    55,
      56,    35,    58,    59,    60,     3,     4,     5,     6,     7,
      37,    10,    38,    11,    31,    13,    14,    15,    31,    31,
      31,     3,     4,     5,     6,     7,    34,    37,    37,    11,
       7,    32,    30,    31,    36,    33,     3,     4,     5,     6,
       7,    32,    37,    41,    11,    37,    33,    37,    30,    31,
      32,    57,    17,    34,    17,    53,    54,    55,    56,    41,
      58,    59,    60,    30,    31,    17,     6,    25,    17,   180,
      37,    53,    54,    55,    41,     3,     4,     5,     6,     7,
      50,   159,    82,    11,   151,    -1,    53,    54,    55,     9,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      30,    -1,    -1,    41,    -1,    -1,    -1,    30,    31,    39,
      40,    41,    42,    43,    44,    53,    54,    55,    41,     3,
       4,     5,     6,     7,    54,    55,    30,    11,    -1,    -1,
      53,    54,    55,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,     9,    -1,    30,    31,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,     9,    -1,    53,
      54,    55,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    30,    54,
      55,    -1,    -1,     9,    -1,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    30,    -1,    32,    -1,    -1,     9,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      30,    -1,    -1,    -1,    -1,     9,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    30,    -1,    32,    -1,
      -1,     9,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    30,    -1,    32,    -1,    -1,     9,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    30,    -1,
      32,    -1,    -1,     9,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    30,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    30,    54,    55,
      -1,    -1,     9,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       9,    54,    55,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    30,    -1,    -1,    51,    52,    -1,    54,    55,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    30,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    10,    12,    95,    96,    97,    98,   115,    37,
       7,   116,     0,    96,     7,    99,   100,   102,    37,     7,
      33,    31,    35,   101,    37,    38,    33,   105,     1,    98,
     115,   117,   118,    32,    98,   103,   104,     6,     7,    99,
     117,    37,   100,   119,   120,    37,    34,   117,   100,    32,
      38,    36,     3,     4,     5,     6,     7,    11,    13,    14,
      15,    30,    31,    41,    53,    54,    55,    56,    58,    59,
      60,   105,   106,   107,   121,   122,    45,    37,    38,   103,
     101,    31,    35,   101,   122,    31,    31,   122,   122,   122,
     122,   122,   122,    31,    31,    37,    37,    34,   106,     9,
      30,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    54,    55,   122,   119,
      32,   122,   123,     6,   121,   122,    37,    37,    98,   111,
     112,   119,   122,    32,   122,   122,   122,     7,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,    38,    32,    36,    37,   113,   122,   119,    32,    37,
      32,    32,    32,   123,   114,   122,    37,   107,    37,   113,
      33,   107,   107,    38,   114,   114,    37,    16,    18,   108,
     109,   110,    57,   114,   114,     3,     6,    17,   110,    34,
     107,    17,    17,   106,   106,   106
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    97,    97,    97,    97,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   109,   109,   110,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     113,   114,   114,   115,   115,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     2,     1,
       1,     3,     1,     2,     3,     4,     4,     3,     1,     3,
       2,     4,     0,     2,     2,     1,     3,     5,     7,     5,
       2,     2,     5,     7,     3,     4,     4,     0,     2,     1,
       5,     4,     4,     3,     4,     3,     3,     2,     1,     2,
       1,     3,     1,     5,     3,     0,     1,     0,     2,     2,
       3,     2,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     2,     2,     2,     2,     4,
       3,     1,     1,     1,     1,     1,     4,     2,     3,     1,
       1,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 71 "parser.y" /* yacc.c:1646  */
    {displayRoot();display((yyvsp[0].ptr),0);/*semantic_Analysis0($1);*/}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,EXT_DEF_LIST,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,EXT_VAR_DEF,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr));}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3,FUNC_DEF,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, EXT_STRUCT_DEC, yylineno,(yyvsp[-1].ptr));}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,TYPE,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));(yyval.ptr)->type=!strcmp((yyvsp[0].type_id),"int")?INT:!strcmp((yyvsp[0].type_id),"string")?STRING:BOOL;}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,EXT_DEC_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ARRAY_LIST,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,ARRAY_LIST,yylineno);(yyval.ptr)->type_int=(yyvsp[-1].type_int);}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ARRAY_LIST,yylineno,(yyvsp[-2].type_int),(yyvsp[0].ptr));(yyval.ptr)->type_int=(yyvsp[-2].type_int);}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,FUNC_DEC,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,FUNC_DEC,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));(yyval.ptr)->ptr[0]=NULL;}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,PARAM_LIST,yylineno,(yyvsp[0].ptr));}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PARAM_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 99 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PARAM_DEC,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,COMP_STM,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr));}
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL; }
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,STM_LIST,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,EXP_STMT,yylineno,(yyvsp[-1].ptr));}
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,RETURN,yylineno,(yyvsp[-1].ptr));}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,IF_THEN,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3,IF_THEN_ELSE,yylineno,(yyvsp[-4].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,WHILE,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr) = mknode(0, CONTINUE, yylineno); strcpy((yyval.ptr)->type_id, "CONTINUE"); }
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr) = mknode(0, BREAK, yylineno); strcpy((yyval.ptr)->type_id, "BREAK"); }
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,FOR,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, SWITCH, yylineno, (yyvsp[-4].ptr), (yyvsp[-1].ptr));}
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, DEFAULT_STMT, yylineno, (yyvsp[0].ptr));}
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, CASE_STMT, yylineno, (yyvsp[0].ptr));(yyval.ptr)->type_int=(yyvsp[-2].type_int);(yyval.ptr)->type=INT;}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, CASE_STMT, yylineno, (yyvsp[0].ptr));(yyval.ptr)->type_char=(yyvsp[-2].type_char);(yyval.ptr)->type=CHAR;}
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, CASE_STMT_LIST, yylineno, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, CASE_STMT_LIST, yylineno,(yyvsp[0].ptr));}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,(yyvsp[-4].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,(yyvsp[-3].ptr),NULL,(yyvsp[0].ptr));}
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL);}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,(yyvsp[-2].ptr),NULL,NULL);}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,NULL,(yyvsp[-1].ptr),NULL);}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC,yylineno,NULL,NULL,(yyvsp[0].ptr));}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC, yylineno, NULL, NULL, NULL);}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, FOR_EXP1, yylineno, (yyvsp[0].ptr));}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, FOR_EXP1, yylineno, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, FOR_EXP2, yylineno, (yyvsp[0].ptr));}
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, FOR_EXP3, yylineno, (yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, FOR_EXP3, yylineno, (yyvsp[0].ptr), NULL);}
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, STRUCT_NEW, yylineno, (yyvsp[-3].ptr), (yyvsp[-1].ptr));}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,STRUCT_DEC,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL; }
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DEF_LIST,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,VAR_DEF,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr));}
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[-1].ptr);}
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,DEC_LIST,yylineno,(yyvsp[0].ptr));}
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DEC_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PLUSASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "PLUSASSIGNOP");}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MINUSASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "MINUSASSIGNOP");}
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, STARASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"STARASSIGNOP");}
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DIVASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"DIVASSIGNOP");}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MODASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "MODASSIGNOP");}
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 190 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,AND,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"AND");}
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,OR,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"OR");}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,RELOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PLUS,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"PLUS");}
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MINUS,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"MINUS");}
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,STAR,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"STAR");}
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DIV,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"DIV");}
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MOD,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"MOD");}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOPLUS,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id, "RPAUTOPLUS");}
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOMINUS,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,"RPAUTOMINUS");}
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOPLUS,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "LPAUTOPLUS");}
#line 2115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOMINUS,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "LPAUTOMINUS");}
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[-1].ptr);}
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,UMINUS,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"UMINUS");}
#line 2133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,NOT,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"NOT");}
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,DPLUS,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"DPLUS");}
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,DPLUS,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,"DPLUS");}
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,FUNC_CALL,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,FUNC_CALL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));}
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 2169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,CHAR,yylineno);(yyval.ptr)->type_char=(yyvsp[0].type_char);(yyval.ptr)->type=CHAR;}
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,STRING,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_string));(yyval.ptr)->type=STRING;}
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,FLOAT,yylineno);(yyval.ptr)->type_float=(yyvsp[0].type_float);(yyval.ptr)->type=FLOAT;}
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,BOOL,yylineno);strcpy((yyval.ptr)->type_bool,(yyvsp[0].type_bool));;(yyval.ptr)->type=BOOL;}
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ARRAY_LIST,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 2199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ID,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 2205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, STRUCT_VISIT, yylineno, (yyvsp[-2].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,INT,yylineno);(yyval.ptr)->type_int=(yyvsp[0].type_int);(yyval.ptr)->type=INT;}
#line 2223 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ARGS,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 2229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ARGS,yylineno,(yyvsp[0].ptr));}
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2239 "parser.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 224 "parser.y" /* yacc.c:1906  */


int main(int argc, char *argv[]){
    yyin=fopen(argv[1],"r");
	if (!yyin) 
        return 0;
	yylineno=1;
	yyparse();
	return 0;
}

void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}
