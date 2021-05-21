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
    INT = 258,
    ID = 259,
    RELOP = 260,
    TYPE = 261,
    STRING = 262,
    BOOL = 263,
    FLOAT = 264,
    DPLUS = 265,
    LP = 266,
    RP = 267,
    LD = 268,
    RD = 269,
    LC = 270,
    RC = 271,
    SEMI = 272,
    COMMA = 273,
    PLUS = 274,
    PLUS_AND_ASSIGNOP = 275,
    PLUS_ONE = 276,
    MINUS = 277,
    MINUS_AND_ASSIGNOP = 278,
    MINUS_ONE = 279,
    STAR = 280,
    DIV = 281,
    MODULO = 282,
    ASSIGNOP = 283,
    AND = 284,
    OR = 285,
    NOT = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    RETURN = 290,
    FOR = 291,
    BREAK = 292,
    CONTINUE = 293,
    SWITCH = 294,
    CASE = 295,
    COLON = 296,
    DEFAULT = 297,
    EXT_DEF_LIST = 298,
    EXT_VAR_DEF = 299,
    FUNC_DEF = 300,
    FUNC_DEC = 301,
    ARRAY_DEC = 302,
    ARRAY_DEF = 303,
    EXT_DEC_LIST = 304,
    PARAM_LIST = 305,
    PARAM_DEC = 306,
    VAR_DEF = 307,
    DEC_LIST = 308,
    DEF_LIST = 309,
    COMP_STM = 310,
    STM_LIST = 311,
    EXP_STMT = 312,
    IF_THEN = 313,
    IF_THEN_ELSE = 314,
    FUNC_CALL = 315,
    ARGS = 316,
    FUNCTION = 317,
    PARAM = 318,
    ARG = 319,
    CALL = 320,
    LABEL = 321,
    GOTO = 322,
    JLT = 323,
    JLE = 324,
    JGT = 325,
    JGE = 326,
    EQ = 327,
    NEQ = 328,
    UMINUS = 329,
    LOWER_THEN_ELSE = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:1909  */

	int    type_int;
    float type_float;
	char  type_string[1024];
    char  type_bool[5];
	char   type_id[32];
	struct ASTNode *ptr;

#line 139 "parser.tab.h" /* yacc.c:1909  */
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
