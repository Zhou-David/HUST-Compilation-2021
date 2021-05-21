%{
#include "parser.tab.h"
#include "string.h"
#include "def.h"
int yycolumn=1;
int line=1;
#define YY_USER_ACTION {yylloc.first_line=yylloc.last_line=yylineno;yylloc.first_column=yycolumn;yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;}
typedef union {
	int type_int;
	int type_float;
	char type_bool[5];
	char type_string[1024];
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
%option yylineno

/*标识符*/
identifier  {Fwords}{Mwords}*
Fwords      [a-zA-Z]|"_"
Mwords      {Fwords}|Digit
Digit       [0-9]

/*转义字符*/
Escape      ("\\t"|"\\n"|"\\\"")

/*整型常量*/
intConstant {Digit}+|{Fnum}{Hnum}+
Fnum        ("0x"|"0X")
Hnum        {Digit}|[a-fA-F]

/*布尔常量*/
boolConstant    ("true"|"false")

/*字符串常量*/
stringConstant  (\"){chars}*(\")
chars           .

/*比较运算符*/
compare     ("<"|">"|"<="|">="|"=="|"!=")

/*变量类型*/
type        ("bool"|"void"|"char"|"int"|"string")

%%
\/\/[^\n]*  {printf("line%d:(注释行,%s)\n",line,yytext);}//匹配注释的正则表达式
\/\*([^(\/)]|\n)*\*\/ {printf("line%d:(注释块,%s)\n",line,yytext);}//匹配注释的正则表达式
"return"    {printf("line%d:(函数返回,%s)\n",line,yytext);return RETURN;}
"if"        {printf("line%d:(条件判断,%s)\n",line,yytext);return IF;}
"else"      {printf("line%d:(条件判断,%s)\n",line,yytext);return ELSE;}
"while"     {printf("line%d:(循环,%s)\n",line,yytext);return WHILE;}
"for"       {printf("line%d:(循环,%s)\n",line,yytext);return FOR;}
"break"     {printf("line%d:(跳出循环,%s)\n",line,yytext);return BREAK;}
"continue"  {printf("line%d:(继续循环,%s)\n",line,yytext);return CONTINUE;}
{type}      {printf("line%d:(类型,%s)\n",line,yytext);strcpy(yylval.type_id,  yytext);return TYPE;}
{Escape}    {printf("line%d:(转义字符,%s)\n",line,yytext);}
{boolConstant}  {printf("line%d:(布尔常量,%s)\n",line,yytext);strcpy(yylval.type_bool,  yytext);return BOOL;}
{intConstant}   {printf("line%d:(整型常量,%s)\n",line,yytext);yylval.type_int=atoi(yytext);return INT;}
{stringConstant}    {printf("line%d:(字符串常量,%s)\n",line,yytext);strcpy(yylval.type_string,  yytext);return STRING;}
";"         {printf("line%d:(分号,%s)\n",line,yytext);return SEMI;}
","         {printf("line%d:(逗号,%s)\n",line,yytext);return COMMA;}
{compare}   { printf("line%d:(比较运算,%s)\n",line,yytext);strcpy(yylval.type_id, yytext);return RELOP;}
"="         {printf("line%d:(赋值运算,%s)\n",line,yytext);return ASSIGNOP;}
"+"         {printf("line%d:(求和运算,%s)\n",line,yytext);return PLUS;}
"-"         {printf("line%d:(求差运算,%s)\n",line,yytext);return MINUS;}
"+="        {printf("line%d:(求和赋值,%s)\n",line,yytext);return PLUS_AND_ASSIGNOP;}
"-="        {printf("line%d:(求差赋值,%s)\n",line,yytext);return MINUS_AND_ASSIGNOP;}
"++"        {printf("line%d:(自增,%s)\n",line,yytext);return PLUS_ONE;}
"--"        {printf("line%d:(自减,%s)\n",line,yytext);return MINUS_ONE;}
"*"         {printf("line%d:(求积运算,%s)\n",line,yytext);return STAR;}
"/"         {printf("line%d:(求商运算,%s)\n",line,yytext);return DIV;}
"%"         {printf("line%d:(模运算,%s)\n",line,yytext);return MODULO;}
"&&"        {printf("line%d:(与运算,%s)\n",line,yytext);return AND;}
"||"        {printf("line%d:(或运算,%s)\n",line,yytext);return OR;}
"!"         {printf("line%d:(取非,%s)\n",line,yytext);return NOT;}
"("         {printf("line%d:(左括号,%s)\n",line,yytext);return LP;}
")"         {printf("line%d:(右括号,%s)\n",line,yytext);return RP;}
"["         {printf("line%d:(左括号,%s)\n",line,yytext);return LD;}
"]"         {printf("line%d:(右括号,%s)\n",line,yytext);return RD;}
"{"         {printf("line%d:(左括号,%s)\n",line,yytext);return LC;}
"}"         {printf("line%d:(右括号,%s)\n",line,yytext);return RC;}
{identifier}    {printf("line%d:(变量,%s)\n",line,yytext);strcpy(yylval.type_id,yytext); return ID;}
[\n]        {++line;}
[ \r\t]     {}
.           {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
%%
int yywrap() 
{ 
	system("pause");
    return 1; 
} 