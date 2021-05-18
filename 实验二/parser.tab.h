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
    DPLUS = 264,
    LP = 265,
    RP = 266,
    LD = 267,
    RD = 268,
    LC = 269,
    RC = 270,
    SEMI = 271,
    COMMA = 272,
    PLUS = 273,
    PLUS_AND_ASSIGNOP = 274,
    PLUS_ONE = 275,
    MINUS = 276,
    MINUS_AND_ASSIGNOP = 277,
    MINUS_ONE = 278,
    STAR = 279,
    DIV = 280,
    MODULO = 281,
    ASSIGNOP = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    RETURN = 289,
    FOR = 290,
    BREAK = 291,
    CONTINUE = 292,
    SWITCH = 293,
    CASE = 294,
    COLON = 295,
    DEFAULT = 296,
    EXT_DEF_LIST = 297,
    EXT_VAR_DEF = 298,
    FUNC_DEF = 299,
    FUNC_DEC = 300,
    EXT_DEC_LIST = 301,
    PARAM_LIST = 302,
    PARAM_DEC = 303,
    VAR_DEF = 304,
    DEC_LIST = 305,
    DEF_LIST = 306,
    COMP_STM = 307,
    STM_LIST = 308,
    EXP_STMT = 309,
    IF_THEN = 310,
    IF_THEN_ELSE = 311,
    FUNC_CALL = 312,
    ARGS = 313,
    FUNCTION = 314,
    PARAM = 315,
    ARG = 316,
    CALL = 317,
    LABEL = 318,
    GOTO = 319,
    JLT = 320,
    JLE = 321,
    JGT = 322,
    JGE = 323,
    EQ = 324,
    NEQ = 325,
    UMINUS = 326,
    LOWER_THEN_ELSE = 327
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:1909  */

	int    type_int;
	string  type_string;
    bool    type_bool;
	char   type_id[32];
	struct ASTNode *ptr;

#line 135 "parser.tab.h" /* yacc.c:1909  */
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
