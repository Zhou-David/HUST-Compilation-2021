%{
#include "parser.tab.h"
#include "string.h"
#include "def.h"
int yycolumn=1;
int line=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
typedef union {
	int type_int;
	char type_char;
	float type_float;
	char type_bool[5];
	char type_string[1024];
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
%option yylineno
%x COMMENT

/*标识符*/
ID  {Fwords}{Mwords}*
Fwords      [a-zA-Z]|"_"
Mwords      {Fwords}|Digit
Digit       [0-9]

/*整型常量*/
INT {Digit}+|{Fnum}{Hnum}+
Fnum        ("0x"|"0X")
Hnum        {Digit}|[a-fA-F]

/*浮点型常量*/
FLOAT [0-9]*[.][0-9]+([eE][-+]?([1-9][0-9*]|[0]))?

/*单字符常量*/
CHAR ['][^\n][']

/*字符串常量*/
STRING ["][^\n]*["]

/*布尔常量*/
BOOL    ("true"|"false")

/*变量类型*/
type        ("bool"|"void"|"char"|"int"|"string"|"float")

/*比较运算符*/
compare     ("<"|">"|"<="|">="|"=="|"!=")

ERRORID [0-9][A-Za-z0-9]*

%%
{INT}	 {printf("line%d:(整型常量,%s)\n",line,yytext);yylval.type_int=atoi(yytext); return INT;}
{FLOAT}  {printf("line%d:(浮点常量,%s)\n",line,yytext);yylval.type_float=atof(yytext); return FLOAT;}
{CHAR}   {printf("line%d:(单字符常量,%s)\n",line,yytext);yylval.type_char=yytext[1];return CHAR;}
{STRING} {printf("line%d:(字符串常量,%s)\n",line,yytext);strncpy(yylval.type_id,yytext+1,strlen(yytext)-2);return STRING;}//string
{BOOL}   {printf("line%d:(布尔常量,%s)\n",line,yytext);strcpy(yylval.type_bool,  yytext);return BOOL;}
{type}   {printf("line%d:(类型,%s)\n",line,yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"return" {printf("line%d:(函数返回,%s)\n",line,yytext);return RETURN;}
"if"     {printf("line%d:(条件判断,%s)\n",line,yytext);return IF;}
"else"   {printf("line%d:(条件判断,%s)\n",line,yytext);return ELSE;}
"while"  {printf("line%d:(while循环,%s)\n",line,yytext);return WHILE;}
"break"	 {printf("line%d:(跳出循环,%s)\n",line,yytext);return BREAK;} // break
"continue" {printf("line%d:(继续循环,%s)\n",line,yytext);return CONTINUE;} //continue
"for"	 {printf("line%d:(循环,%s)\n",line,yytext);return FOR;}//for
"switch" {printf("line%d:(switch分支,%s)\n",line,yytext);return SWITCH;}//switch
"case"	 {printf("line%d:(case语句,%s)\n",line,yytext);return CASE;}//case
"struct" {printf("line%d:(结构体,%s)\n",line,yytext);return STRUCT;}//struct
"default" {printf("line%d:(default语句,%s)\n",line,yytext);return DEFAULT;}//DEFAULT

{ID}     {printf("line%d:(变量,%s)\n",line,yytext);strcpy(yylval.type_id,  yytext); return ID;}
{ERRORID} {printf("line%d:(错误的变量定义,%s)\n",line,yytext);strcpy(yylval.type_id,yytext);return ERRORID;}//错误标识符
":"		 {printf("line%d:(冒号,%s)\n",line,yytext);return COLON;}
";"		 {printf("line%d:(分号,%s)\n",line,yytext);return SEMI;}
","		 {printf("line%d:(逗号,%s)\n",line,yytext);return COMMA;}
{compare} {printf("line%d:(比较运算,%s)\n",line,yytext);strcpy(yylval.type_id, yytext);return RELOP;}
"="		 {printf("line%d:(赋值运算,%s)\n",line,yytext);return ASSIGNOP;}
"+"		 {printf("line%d:(求和运算,%s)\n",line,yytext);return PLUS;}
"-"		 {printf("line%d:(求差运算,%s)\n",line,yytext);return MINUS;}
"*"		 {printf("line%d:(求积运算,%s)\n",line,yytext);return STAR;}
"/"		 {printf("line%d:(求商运算,%s)\n",line,yytext);return DIV;}
"."      {printf("line%d:(点号,%s)\n",line,yytext);return DOT;}
"%"      {printf("line%d:(模运算,%s)\n",line,yytext);return MOD;}
"&&"     {printf("line%d:(与运算,%s)\n",line,yytext);return AND;}
"||"     {printf("line%d:(或运算,%s)\n",line,yytext);return OR;}
"!"		 {printf("line%d:(取非,%s)\n",line,yytext);return NOT;}
"++"     {printf("line%d:(自增,%s)\n",line,yytext); return AUTOPLUS;}//自增
"--"     {printf("line%d:(自减,%s)\n",line,yytext); return AUTOMINUS;}//自减
"+="     {printf("line%d:(求和赋值,%s)\n",line,yytext); return PLUSASSIGNOP;}
"-="     {printf("line%d:(求差赋值,%s)\n",line,yytext); return MINUSASSIGNOP;}
"*="     {printf("line%d:(求积赋值,%s)\n",line,yytext);return STARASSIGNOP;}
"/="     {printf("line%d:(求商赋值,%s)\n",line,yytext);return DIVASSIGNOP;}
"%="     {printf("line%d:(求模赋值,%s)\n",line,yytext);return MODASSIGNOP;}
"("		 {printf("line%d:(左括号小,%s)\n",line,yytext);return LP;}
")"		 {printf("line%d:(右括号小,%s)\n",line,yytext);return RP;}
"{"		 {printf("line%d:(左括号大,%s)\n",line,yytext);return LC;}
"}"		 {printf("line%d:(右括号大,%s)\n",line,yytext);return RC;}
"["      {printf("line%d:(左括号中,%s)\n",line,yytext);return LB;}
"]"      {printf("line%d:(右括号中,%s)\n",line,yytext);return RB;}
[\n]     {printf("line%d:(换行符,\\n)\n",line);yycolumn=1;line++;}   
[ \r\t]  {}   
.		 {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
\/\/[^\n]*  {printf("(%s, LINECOMMENT)\n", yytext);}//匹配注释
 /* 注释 */
"/*"		{BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>>	{printf("%s: %d: Unterminated comment\n", yytext, yylineno);return 0;}
%%
//用户函数部分
/* 和bison联用时，不需要这部分
void main()
{
yylex();
return 0;
}
*/

int yywrap()
{
	system("pause");
    return 1;
}