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
    ARRAY = 262,
    STRING = 263,
    BOOL = 264,
    FLOAT = 265,
    DPLUS = 266,
    LP = 267,
    RP = 268,
    LD = 269,
    RD = 270,
    LC = 271,
    RC = 272,
    SEMI = 273,
    COMMA = 274,
    DOT = 275,
    PLUS = 276,
    PLUS_AND_ASSIGNOP = 277,
    PLUS_ONE = 278,
    MINUS = 279,
    MINUS_AND_ASSIGNOP = 280,
    MINUS_ONE = 281,
    STAR = 282,
    DIV = 283,
    MODULO = 284,
    ASSIGNOP = 285,
    AND = 286,
    OR = 287,
    NOT = 288,
    IF = 289,
    ELSE = 290,
    WHILE = 291,
    RETURN = 292,
    FOR = 293,
    BREAK = 294,
    CONTINUE = 295,
    SWITCH = 296,
    CASE = 297,
    COLON = 298,
    DEFAULT = 299,
    EXT_DEF_LIST = 300,
    EXT_VAR_DEF = 301,
    FUNC_DEF = 302,
    FUNC_DEC = 303,
    ARRAY_DEC = 304,
    ARRAY_DEF = 305,
    EXT_DEC_LIST = 306,
    PARAM_LIST = 307,
    PARAM_DEC = 308,
    VAR_DEF = 309,
    DEC_LIST = 310,
    DEF_LIST = 311,
    COMP_STM = 312,
    STM_LIST = 313,
    EXP_STMT = 314,
    IF_THEN = 315,
    IF_THEN_ELSE = 316,
    FUNC_CALL = 317,
    ARGS = 318,
    FUNCTION = 319,
    PARAM = 320,
    ARG = 321,
    CALL = 322,
    LABEL = 323,
    GOTO = 324,
    JLT = 325,
    JLE = 326,
    JGT = 327,
    JGE = 328,
    EQ = 329,
    NEQ = 330,
    STRUCT = 331,
    STRUCT_VISIT = 332,
    STRUCT_NEW = 333,
    STRUCT_DEC = 334,
    EXT_STRUCT_DEC = 335,
    UMINUS = 336,
    LOWER_THEN_ELSE = 337
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

#line 146 "parser.tab.h" /* yacc.c:1909  */
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
