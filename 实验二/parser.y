%error-verbose
%locations
%{
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct ASTNode *,int);
%}

%union {
	int    type_int;
	string  type_string;
    bool    type_bool;
	char   type_id[32];
	struct ASTNode *ptr;
};

//  %type ������ս��������ֵ����
%type  <ptr> program ExtDefList ExtDef  Specifier ExtDecList FuncDec CompSt VarList VarDec ParamDec Stmt StmList DefList Def DecList Dec Exp Args CaseStmtList0 CaseStmtList

//% token �����ս��������ֵ����
%token <type_int> INT              /*ָ��INT������ֵ��type_int���дʷ������õ�����ֵ*/
%token <type_id> ID  RELOP TYPE    /*ָ��ID,RELOP ������ֵ��type_id���дʷ������õ��ı�ʶ���ַ���*/
%token <type_string> STRING          /*ָ��ID������ֵ��type_id���дʷ������õ��ı�ʶ���ַ���*/
%token <type_bool> BOOL

%token DPLUS LP RP LD RD LC RC SEMI COMMA      /*��bison�Ը��ļ�����ʱ��������-d�����ɵ�.tab.h�и���Щ���ʽ��б��룬����lex.l�а���parser.tab.hʹ����Щ����������*/
%token PLUS PLUS_AND_ASSIGNOP PLUS_ONE MINUS MINUS_AND_ASSIGNOP MINUS_ONE STAR DIV MODULO ASSIGNOP AND OR NOT IF ELSE WHILE RETURN FOR BREAK CONTINUE SWITCH CASE COLON DEFAULT
/*����Ϊ��������token�����α����ö�ٳ�������ΪAST������ͱ��*/
%token EXT_DEF_LIST EXT_VAR_DEF FUNC_DEF FUNC_DEC EXT_DEC_LIST PARAM_LIST PARAM_DEC VAR_DEF DEC_LIST DEF_LIST COMP_STM STM_LIST EXP_STMT IF_THEN IF_THEN_ELSE
%token FUNC_CALL ARGS FUNCTION PARAM ARG CALL LABEL GOTO JLT JLE JGT JGE EQ NEQ


%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left PLUS_ONE MINUS_ONE
%left PLUS_AND_ASSIGNOP
%left STAR DIV MODULO
%right UMINUS NOT DPLUS

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%

program: ExtDefList    { display($1,0); semantic_Analysis0($1);}     //��ʾ�﷨��,�������
         ; 
ExtDefList: {$$=NULL;}
          | ExtDef ExtDefList {$$=mknode(2,EXT_DEF_LIST,yylineno,$1,$2);}   //ÿһ��EXTDEFLIST�Ľ�㣬���1��������Ӧһ���ⲿ������������
          ;  
ExtDef:   Specifier ExtDecList SEMI   {$$=mknode(2,EXT_VAR_DEF,yylineno,$1,$2);}   //�ý���Ӧһ���ⲿ��������
         |Specifier FuncDec CompSt    {$$=mknode(3,FUNC_DEF,yylineno,$1,$2,$3);}         //�ý���Ӧһ����������
         | error SEMI   {$$=NULL;}
         ;
Specifier:  TYPE    {$$=mknode(0,TYPE,yylineno);strcpy($$->type_id,$1);$$->type=!strcmp($1,"int")?INT:!strcmp($1,"string")?STRING:BOOL;}   
           ;      
ExtDecList:  VarDec      {$$=$1;}       /*ÿһ��EXT_DECLIST�Ľ�㣬���һ��������Ӧһ��������(ID���͵Ľ��),�ڶ���������Ӧʣ�µ��ⲿ������*/
           | VarDec COMMA ExtDecList {$$=mknode(2,EXT_DEC_LIST,yylineno,$1,$3);}
           ;  
VarDec:  ID          {$$=mknode(0,ID,yylineno);strcpy($$->type_id,$1);}   //ID��㣬��ʶ�����Ŵ���Ž���type_id
         ;
FuncDec: ID LP VarList RP   {$$=mknode(1,FUNC_DEC,yylineno,$3);strcpy($$->type_id,$1);}//�����������$$->type_id
		|ID LP  RP   {$$=mknode(0,FUNC_DEC,yylineno);strcpy($$->type_id,$1);$$->ptr[0]=NULL;}//�����������$$->type_id

        ;  
VarList: ParamDec  {$$=mknode(1,PARAM_LIST,yylineno,$1);}
        | ParamDec COMMA  VarList  {$$=mknode(2,PARAM_LIST,yylineno,$1,$3);}
        ;
ParamDec: Specifier VarDec         {$$=mknode(2,PARAM_DEC,yylineno,$1,$2);}
         ;

CompSt: LC DefList StmList RC    {$$=mknode(2,COMP_STM,yylineno,$2,$3);}
       ;
StmList: {$$=NULL; }  
        | Stmt StmList  {$$=mknode(2,STM_LIST,yylineno,$1,$2);}
        ;
Stmt:   Exp SEMI    {$$=mknode(1,EXP_STMT,yylineno,$1);}
      | CompSt      {$$=$1;}      //���������ֱ����Ϊ����㣬���������µĽ��
      | RETURN Exp SEMI   {$$=mknode(1,RETURN,yylineno,$2);}
      | IF LP Exp RP Stmt %prec LOWER_THEN_ELSE   {$$=mknode(2,IF_THEN,yylineno,$3,$5);}
      | IF LP Exp RP Stmt ELSE Stmt   {$$=mknode(3,IF_THEN_ELSE,yylineno,$3,$5,$7);}
      | WHILE LP Exp RP Stmt {$$=mknode(2,WHILE,yylineno,$3,$5);}
      | FOR LP Exp SEMI Exp SEMI Exp RP Stmt {$$=mknode(2,FOR,yylineno,$3,$5)} 
      ;
DefList: {$$=NULL; }
        | Def DefList {$$=mknode(2,DEF_LIST,yylineno,$1,$2);}
        | error SEMI   {$$=NULL;}
        ;
Def:    Specifier DecList SEMI {$$=mknode(2,VAR_DEF,yylineno,$1,$2);}
        ;
DecList: Dec  {$$=mknode(1,DEC_LIST,yylineno,$1);}
       | Dec COMMA DecList  {$$=mknode(2,DEC_LIST,yylineno,$1,$3);}
	   ;
Dec:     VarDec  {$$=$1;}
       | VarDec ASSIGNOP Exp  {$$=mknode(2,ASSIGNOP,yylineno,$1,$3);strcpy($$->type_id,"ASSIGNOP");}
       ;
Exp:    Exp ASSIGNOP Exp {$$=mknode(2,ASSIGNOP,yylineno,$1,$3);strcpy($$->type_id,"ASSIGNOP");}//$$���type_id����δ�ã����ô�������
      | Exp AND Exp   {$$=mknode(2,AND,yylineno,$1,$3);strcpy($$->type_id,"AND");}
      | Exp OR Exp    {$$=mknode(2,OR,yylineno,$1,$3);strcpy($$->type_id,"OR");}
      | Exp RELOP Exp {$$=mknode(2,RELOP,yylineno,$1,$3);strcpy($$->type_id,$2);}  //�ʷ�������ϵ�����������ֵ������$2��
      | Exp PLUS Exp  {$$=mknode(2,PLUS,yylineno,$1,$3);strcpy($$->type_id,"PLUS");}
      | Exp PLUS_AND_ASSIGNOP Exp {$$=mknode(2,PLUS_AND_ASSIGNOP,yylineno,$1,$3);strcpy($$->type_id,"PLUS_AND_ASSIGN");}
      | Exp PLUS_ONE  {$$=mknode(1,PLUS_ONE,yylineno,$1);strcpy($$->type_id,"PLUS_ONE");}
      | Exp MINUS Exp {$$=mknode(2,MINUS,yylineno,$1,$3);strcpy($$->type_id,"MINUS");}
      | Exp MINUS_AND_ASSIGNOP Exp {$$=mknode(2,MINUS_AND_ASSIGNOP,yylineno,$1,$3);strcpy($$->type_id,"MINUS_AND_ASSIGN");}
      | Exp MINUS_ONE  {$$=mknode(1,MINUS_ONE,yylineno,$1);strcpy($$->type_id,"MINUS_ONE");}
      | Exp STAR Exp  {$$=mknode(2,STAR,yylineno,$1,$3);strcpy($$->type_id,"STAR");}
      | Exp DIV Exp   {$$=mknode(2,DIV,yylineno,$1,$3);strcpy($$->type_id,"DIV");}
      | Exp MODULO Exp {$$=mknode(2,MODULO,yylineno,$1,$3);strcpy($$->type_id,"MODULO");}
      | LP Exp RP     {$$=$2;}
      | MINUS Exp %prec UMINUS   {$$=mknode(1,UMINUS,yylineno,$2);strcpy($$->type_id,"UMINUS");}
      | NOT Exp       {$$=mknode(1,NOT,yylineno,$2);strcpy($$->type_id,"NOT");}
      | DPLUS  Exp      {$$=mknode(1,DPLUS,yylineno,$2);strcpy($$->type_id,"DPLUS");}
      |   Exp DPLUS      {$$=mknode(1,DPLUS,yylineno,$1);strcpy($$->type_id,"DPLUS");}
      | ID LP Args RP {$$=mknode(1,FUNC_CALL,yylineno,$3);strcpy($$->type_id,$1);}
      | ID LP RP      {$$=mknode(0,FUNC_CALL,yylineno);strcpy($$->type_id,$1);}
      | ID            {$$=mknode(0,ID,yylineno);strcpy($$->type_id,$1);}
      | INT           {$$=mknode(0,INT,yylineno);$$->type_int=$1;$$->type=INT;}
      | STRING        {$$=mknode(0,STRING,yylineno);$$->type_string=$1;$$->type=STRING;}
      | BOOL          {$$=mknode(0,BOOL,yylineno);$$->type_bool=$1;$$->type=BOOL;}
      ;
Args:    Exp COMMA Args    {$$=mknode(2,ARGS,yylineno,$1,$3);}
       | Exp               {$$=mknode(1,ARGS,yylineno,$1);}
       ;
       
%%

int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return;
	yylineno=1;
	yyparse();
	return 0;
	}

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}