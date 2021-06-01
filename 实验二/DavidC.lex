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

/*��ʶ��*/
ID  {Fwords}{Mwords}*
Fwords      [a-zA-Z]|"_"
Mwords      {Fwords}|Digit
Digit       [0-9]

/*���ͳ���*/
INT {Digit}+|{Fnum}{Hnum}+
Fnum        ("0x"|"0X")
Hnum        {Digit}|[a-fA-F]

/*�����ͳ���*/
FLOAT [0-9]*[.][0-9]+([eE][-+]?([1-9][0-9*]|[0]))?

/*���ַ�����*/
CHAR ['][^\n][']

/*�ַ�������*/
STRING ["][^\n]*["]

/*��������*/
BOOL    ("true"|"false")

/*��������*/
type        ("bool"|"void"|"char"|"int"|"string"|"float")

/*�Ƚ������*/
compare     ("<"|">"|"<="|">="|"=="|"!=")

ERRORID [0-9][A-Za-z0-9]*

%%
{INT}	 {printf("line%d:(���ͳ���,%s)\n",line,yytext);yylval.type_int=atoi(yytext); return INT;}
{FLOAT}  {printf("line%d:(���㳣��,%s)\n",line,yytext);yylval.type_float=atof(yytext); return FLOAT;}
{CHAR}   {printf("line%d:(���ַ�����,%s)\n",line,yytext);yylval.type_char=yytext[1];return CHAR;}
{STRING} {printf("line%d:(�ַ�������,%s)\n",line,yytext);strncpy(yylval.type_id,yytext+1,strlen(yytext)-2);return STRING;}//string
{BOOL}   {printf("line%d:(��������,%s)\n",line,yytext);strcpy(yylval.type_bool,  yytext);return BOOL;}
{type}   {printf("line%d:(����,%s)\n",line,yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"return" {printf("line%d:(��������,%s)\n",line,yytext);return RETURN;}
"if"     {printf("line%d:(�����ж�,%s)\n",line,yytext);return IF;}
"else"   {printf("line%d:(�����ж�,%s)\n",line,yytext);return ELSE;}
"while"  {printf("line%d:(whileѭ��,%s)\n",line,yytext);return WHILE;}
"break"	 {printf("line%d:(����ѭ��,%s)\n",line,yytext);return BREAK;} // break
"continue" {printf("line%d:(����ѭ��,%s)\n",line,yytext);return CONTINUE;} //continue
"for"	 {printf("line%d:(ѭ��,%s)\n",line,yytext);return FOR;}//for
"switch" {printf("line%d:(switch��֧,%s)\n",line,yytext);return SWITCH;}//switch
"case"	 {printf("line%d:(case���,%s)\n",line,yytext);return CASE;}//case
"struct" {printf("line%d:(�ṹ��,%s)\n",line,yytext);return STRUCT;}//struct
"default" {printf("line%d:(default���,%s)\n",line,yytext);return DEFAULT;}//DEFAULT

{ID}     {printf("line%d:(����,%s)\n",line,yytext);strcpy(yylval.type_id,  yytext); return ID;}
{ERRORID} {printf("line%d:(����ı�������,%s)\n",line,yytext);strcpy(yylval.type_id,yytext);return ERRORID;}//�����ʶ��
":"		 {printf("line%d:(ð��,%s)\n",line,yytext);return COLON;}
";"		 {printf("line%d:(�ֺ�,%s)\n",line,yytext);return SEMI;}
","		 {printf("line%d:(����,%s)\n",line,yytext);return COMMA;}
{compare} {printf("line%d:(�Ƚ�����,%s)\n",line,yytext);strcpy(yylval.type_id, yytext);return RELOP;}
"="		 {printf("line%d:(��ֵ����,%s)\n",line,yytext);return ASSIGNOP;}
"+"		 {printf("line%d:(�������,%s)\n",line,yytext);return PLUS;}
"-"		 {printf("line%d:(�������,%s)\n",line,yytext);return MINUS;}
"*"		 {printf("line%d:(�������,%s)\n",line,yytext);return STAR;}
"/"		 {printf("line%d:(��������,%s)\n",line,yytext);return DIV;}
"."      {printf("line%d:(���,%s)\n",line,yytext);return DOT;}
"%"      {printf("line%d:(ģ����,%s)\n",line,yytext);return MOD;}
"&&"     {printf("line%d:(������,%s)\n",line,yytext);return AND;}
"||"     {printf("line%d:(������,%s)\n",line,yytext);return OR;}
"!"		 {printf("line%d:(ȡ��,%s)\n",line,yytext);return NOT;}
"++"     {printf("line%d:(����,%s)\n",line,yytext); return AUTOPLUS;}//����
"--"     {printf("line%d:(�Լ�,%s)\n",line,yytext); return AUTOMINUS;}//�Լ�
"+="     {printf("line%d:(��͸�ֵ,%s)\n",line,yytext); return PLUSASSIGNOP;}
"-="     {printf("line%d:(��ֵ,%s)\n",line,yytext); return MINUSASSIGNOP;}
"*="     {printf("line%d:(�����ֵ,%s)\n",line,yytext);return STARASSIGNOP;}
"/="     {printf("line%d:(���̸�ֵ,%s)\n",line,yytext);return DIVASSIGNOP;}
"%="     {printf("line%d:(��ģ��ֵ,%s)\n",line,yytext);return MODASSIGNOP;}
"("		 {printf("line%d:(������С,%s)\n",line,yytext);return LP;}
")"		 {printf("line%d:(������С,%s)\n",line,yytext);return RP;}
"{"		 {printf("line%d:(�����Ŵ�,%s)\n",line,yytext);return LC;}
"}"		 {printf("line%d:(�����Ŵ�,%s)\n",line,yytext);return RC;}
"["      {printf("line%d:(��������,%s)\n",line,yytext);return LB;}
"]"      {printf("line%d:(��������,%s)\n",line,yytext);return RB;}
[\n]     {printf("line%d:(���з�,\\n)\n",line);yycolumn=1;line++;}   
[ \r\t]  {}   
.		 {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
\/\/[^\n]*  {printf("(%s, LINECOMMENT)\n", yytext);}//ƥ��ע��
 /* ע�� */
"/*"		{BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>>	{printf("%s: %d: Unterminated comment\n", yytext, yylineno);return 0;}
%%
//�û���������
/* ��bison����ʱ������Ҫ�ⲿ��
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