/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ARRAY_DEC = 345,
    ARRAY_DF = 346,
    ARRAY_CALL = 347,
    UMINUS = 348,
    DMINUS = 349,
    LOWER_THEN_ELSE = 350
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:1909  */

	int type_int;
    char type_char;
	float type_float;
    char type_bool[5];
    char type_string[1024];
	char type_id[32];
	struct ASTNode *ptr;

#line 160 "parser.tab.h" /* yacc.c:1909  */
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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
