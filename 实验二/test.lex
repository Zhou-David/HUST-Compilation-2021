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

/*��ʶ��*/
identifier  {Fwords}{Mwords}*
Fwords      [a-zA-Z]|"_"
Mwords      {Fwords}|Digit
Digit       [0-9]

/*ת���ַ�*/
Escape      ("\\t"|"\\n"|"\\\"")

/*���ͳ���*/
intConstant {Digit}+|{Fnum}{Hnum}+
Fnum        ("0x"|"0X")
Hnum        {Digit}|[a-fA-F]

/*��������*/
boolConstant    ("true"|"false")

/*�ַ�������*/
stringConstant  (\"){chars}*(\")
chars           .

/*�Ƚ������*/
compare     ("<"|">"|"<="|">="|"=="|"!=")

/*��������*/
type        ("bool"|"void"|"char"|"int"|"string")

%%
\/\/[^\n]*  {printf("line%d:(ע����,%s)\n",line,yytext);}//ƥ��ע�͵�������ʽ
\/\*([^(\/)]|\n)*\*\/ {printf("line%d:(ע�Ϳ�,%s)\n",line,yytext);}//ƥ��ע�͵�������ʽ
"return"    {printf("line%d:(��������,%s)\n",line,yytext);return RETURN;}
"if"        {printf("line%d:(�����ж�,%s)\n",line,yytext);return IF;}
"else"      {printf("line%d:(�����ж�,%s)\n",line,yytext);return ELSE;}
"while"     {printf("line%d:(ѭ��,%s)\n",line,yytext);return WHILE;}
"for"       {printf("line%d:(ѭ��,%s)\n",line,yytext);return FOR;}
"break"     {printf("line%d:(����ѭ��,%s)\n",line,yytext);return BREAK;}
"continue"  {printf("line%d:(����ѭ��,%s)\n",line,yytext);return CONTINUE;}
{type}      {printf("line%d:(����,%s)\n",line,yytext);strcpy(yylval.type_id,  yytext);return TYPE;}
{Escape}    {printf("line%d:(ת���ַ�,%s)\n",line,yytext);}
{boolConstant}  {printf("line%d:(��������,%s)\n",line,yytext);strcpy(yylval.type_bool,  yytext);return BOOL;}
{intConstant}   {printf("line%d:(���ͳ���,%s)\n",line,yytext);yylval.type_int=atoi(yytext);return INT;}
{stringConstant}    {printf("line%d:(�ַ�������,%s)\n",line,yytext);strcpy(yylval.type_string,  yytext);return STRING;}
";"         {printf("line%d:(�ֺ�,%s)\n",line,yytext);return SEMI;}
","         {printf("line%d:(����,%s)\n",line,yytext);return COMMA;}
{compare}   { printf("line%d:(�Ƚ�����,%s)\n",line,yytext);strcpy(yylval.type_id, yytext);return RELOP;}
"="         {printf("line%d:(��ֵ����,%s)\n",line,yytext);return ASSIGNOP;}
"+"         {printf("line%d:(�������,%s)\n",line,yytext);return PLUS;}
"-"         {printf("line%d:(�������,%s)\n",line,yytext);return MINUS;}
"+="        {printf("line%d:(��͸�ֵ,%s)\n",line,yytext);return PLUS_AND_ASSIGNOP;}
"-="        {printf("line%d:(��ֵ,%s)\n",line,yytext);return MINUS_AND_ASSIGNOP;}
"++"        {printf("line%d:(����,%s)\n",line,yytext);return PLUS_ONE;}
"--"        {printf("line%d:(�Լ�,%s)\n",line,yytext);return MINUS_ONE;}
"*"         {printf("line%d:(�������,%s)\n",line,yytext);return STAR;}
"/"         {printf("line%d:(��������,%s)\n",line,yytext);return DIV;}
"%"         {printf("line%d:(ģ����,%s)\n",line,yytext);return MODULO;}
"&&"        {printf("line%d:(������,%s)\n",line,yytext);return AND;}
"||"        {printf("line%d:(������,%s)\n",line,yytext);return OR;}
"!"         {printf("line%d:(ȡ��,%s)\n",line,yytext);return NOT;}
"("         {printf("line%d:(������,%s)\n",line,yytext);return LP;}
")"         {printf("line%d:(������,%s)\n",line,yytext);return RP;}
"["         {printf("line%d:(������,%s)\n",line,yytext);return LD;}
"]"         {printf("line%d:(������,%s)\n",line,yytext);return RD;}
"{"         {printf("line%d:(������,%s)\n",line,yytext);return LC;}
"}"         {printf("line%d:(������,%s)\n",line,yytext);return RC;}
{identifier}    {printf("line%d:(����,%s)\n",line,yytext);strcpy(yylval.type_id,yytext); return ID;}
[\n]        {++line;}
[ \r\t]     {}
.           {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
%%
int yywrap() 
{ 
	system("pause");
    return 1; 
} 