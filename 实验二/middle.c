#include "def.h"
#define DEBUG 1

char *strcat0(char *s1,char *s2){
    static char result[10];
    strcpy(result,s1);
    strcat(result,s2);
    return result;
}

char *newAlias() {
    static int no=1;
    char s[10];
    itoa(no++,s,10);
    return strcat0("v",s);
}

char *newLabel() {
    static int no=1;
    char s[10];
    itoa(no++,s,10);
    return strcat0("label",s);
}

char *newTemp(){
    static int no=1;
    char s[10];
    itoa(no++,s,10);
    return strcat0("temp",s);
}

//����һ��TAC����Ľ����ɵ�˫��ѭ����������ͷָ��
struct codenode *genIR(int op,struct opn opn1,struct opn opn2,struct opn result){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=op;
    h->opn1=opn1;
    h->opn2=opn2;
    h->result=result;
    h->next=h->prior=h;
    return h;
}

//����һ�������䣬����ͷָ��
struct codenode *genLabel(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=LABEL;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//����GOTO��䣬����ͷָ��
struct codenode *genGoto(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=GOTO;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//�ϲ�����м�����˫��ѭ��������β����
struct codenode *merge(int num,...){
    struct codenode *h1,*h2,*p,*t1,*t2;
    va_list ap;
    va_start(ap,num);
    h1=va_arg(ap,struct codenode *);
    while (--num>0) {
        h2=va_arg(ap,struct codenode *);
        if (h1==NULL) h1=h2;
        else if (h2){
            t1=h1->prior;
            t2=h2->prior;
            t1->next=h2;
            t2->next=h1;
            h1->prior=t2;
            h2->prior=t1;
            }
        }
    va_end(ap);
    return h1;
}

//����м����
void prnIR(struct codenode *head){
    char opnstr1[32],opnstr2[32],resultstr[32];
    struct codenode *h=head;
    do {
        if (h->opn1.kind==INT)
             sprintf(opnstr1,"#%d",h->opn1.const_int);
        if (h->opn1.kind==FLOAT)
             sprintf(opnstr1,"#%f",h->opn1.const_float);
        if (h->opn1.kind==BOOL)
            sprintf(opnstr1, "%s", h->opn1.const_bool);
        if (h->opn1.kind==CHAR)
            sprintf(opnstr1, "%s", h->opn1.const_char);
        if (h->opn1.kind == STRING)
            sprintf(opnstr1, "%s", h->opn1.const_string);
        if (h->opn1.kind==ID)
             sprintf(opnstr1,"%s",h->opn1.id);
        if (h->opn2.kind==INT)
             sprintf(opnstr2,"#%d",h->opn2.const_int);
        if (h->opn2.kind==FLOAT)
             sprintf(opnstr2,"#%f",h->opn2.const_float);
        if (h->opn2.kind == BOOL)
            sprintf(opnstr2, "%s", h->opn2.const_bool);
        if (h->opn2.kind == STRING)
            sprintf(opnstr2, "%s", h->opn2.const_string);
        if (h->opn2.kind==ID)
             sprintf(opnstr2,"%s",h->opn2.id);
        sprintf(resultstr,"%s",h->result.id);
        switch (h->op) {
            case ASSIGNOP:  printf("  %s := %s\n",resultstr,opnstr1);
                            break;
            case PLUS:
            case PLUSASSIGNOP:
            case AUTOPLUS:
            case MINUS:
            case MINUSASSIGNOP:
            case AUTOMINUS:
            case STAR:
            case DIV: printf("  %s := %s %s %s\n", resultstr, opnstr1, \
                h->op == PLUS ? "+" : h->op == MINUS ? "-" : h->op == STAR ? "*" : \
                h->op == PLUSASSIGNOP ? "+=" : h->op == AUTOPLUS ? "++" : \
                h->op == MINUSASSIGNOP ? "-=" : h->op == AUTOMINUS ? "--" : "\\", opnstr2);
                      break;
            case FUNCTION: printf("\nFUNCTION %s :\n",h->result.id);
                           break;
            case PARAM:    printf("  PARAM %s\n",h->result.id);
                           break;
            case LABEL:    printf("LABEL %s :\n",h->result.id);
                           break;
            case GOTO:     printf("  GOTO %s\n",h->result.id);
                           break;
            case JLE:      printf("  IF %s <= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JLT:      printf("  IF %s < %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JGE:      printf("  IF %s >= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JGT:      printf("  IF %s > %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case EQ:       printf("  IF %s == %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case NEQ:      printf("  IF %s != %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case ARG:      printf("  ARG %s\n",h->result.id);
                           break;
            case CALL:     if (!strcmp(opnstr1,"write"))
                                printf("  CALL  %s\n", opnstr1);
                            else
                                printf("  %s := CALL %s\n",resultstr, opnstr1);
                           break;
            case RETURN:   if (h->result.kind)
                                printf("  RETURN %s\n",resultstr);
                           else
                                printf("  RETURN\n");
                           break;

        }
    h=h->next;
    } while (h!=head);
}
void semantic_error(int line,char *msg1,char *msg2){
    //�������ֻ�ռ�������Ϣ�����һ����ʾ
    //printf("��%d��,%s %s\n",line,msg1,msg2);
}
void prn_symbol(){ //��ʾ���ű�
    int i=0;
    printf("%6s %6s %6s  %6s %4s %6s\n","������","�� ��","�� ��","��  ��","���","ƫ����");
    for(i=0;i<symbolTable.index;i++)
        printf("%6s %6s %6d  %6s %4c %6d\n",symbolTable.symbols[i].name,\
                symbolTable.symbols[i].alias,symbolTable.symbols[i].level,\
                symbolTable.symbols[i].type==INT?"int": symbolTable.symbols[i].type == BOOL?"bool":"string",\
                symbolTable.symbols[i].flag,symbolTable.symbols[i].offset);
}

int searchSymbolTable(char *name) {
    int i,flag=0;
    for(i=symbolTable.index-1;i>=0;i--){
        if (symbolTable.symbols[i].level==0)
            flag=1;
        if (flag && symbolTable.symbols[i].level==1)
            continue;   //����ǰ�溯������ʽ��������
        if (!strcmp(symbolTable.symbols[i].name, name))  return i;
    }
    return -1;
}
int fillSymbolTable(char *name,char *alias,int level,int type,char flag,int offset) {
    //���ȸ���name����ű������ظ����� �ظ����巵��-1
    int i;
    /*���Ų��أ������ⲿ��������ǰ�к������壬
    ���β������ڷ��ű��У���ʱ���ⲿ������ǰ�������β������������*/
    for(i=symbolTable.index-1; i>=0 && (symbolTable.symbols[i].level==level||level==0); i--) {
        if (level==0 && symbolTable.symbols[i].level==1) continue;  //�ⲿ�������ββ��رȽ�����
        if (!strcmp(symbolTable.symbols[i].name, name))  return -1;
        }
    //��д���ű�����
    strcpy(symbolTable.symbols[symbolTable.index].name,name);
    strcpy(symbolTable.symbols[symbolTable.index].alias,alias);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].type=type;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //���ص��Ƿ����ڷ��ű��е�λ����ţ��м��������ʱ�������ȡ�����ű���
}

//��д��ʱ���������ű�������ʱ�����ڷ��ű��е�λ��
int fill_Temp(char *name,int level,int type,char flag,int offset) {
    strcpy(symbolTable.symbols[symbolTable.index].name,"");
    strcpy(symbolTable.symbols[symbolTable.index].alias,name);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].type=type;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //���ص�����ʱ�����ڷ��ű��е�λ�����
}

void ext_var_list(struct ASTNode *T){  //��������б�
    int rtn,num=1;
    switch (T->kind){
        case EXT_DEC_LIST:
                T->ptr[0]->type=T->type;              //�������������´��ݱ������
                T->ptr[0]->offset=T->offset;          //�ⲿ������ƫ�������´���
                T->ptr[1]->type=T->type;              //�������������´��ݱ������
                T->ptr[1]->offset=T->offset+T->width; //�ⲿ������ƫ�������´���
                T->ptr[1]->width=T->width;
                ext_var_list(T->ptr[0]);
                ext_var_list(T->ptr[1]);
                T->num=T->ptr[1]->num+1;
                break;
        case ID:
            rtn=fillSymbolTable(T->type_id,newAlias(),LEV,T->type,'V',T->offset);  //���һ��������
            if (rtn==-1)
                semantic_error(T->pos,T->type_id, "�����ظ�����");
            else T->place=rtn;
            T->num=1;
            break;
        }
    }

int  match_param(int i,struct ASTNode *T){
    int j,num=symbolTable.symbols[i].paramnum;
    int type1,type2,pos=T->pos;
    T=T->ptr[0];
    if (num==0 && T==NULL) return 1;
    for (j=1;j<=num;j++) {
        if (!T){
            semantic_error(pos,"", "�������ò���̫��!");
            return 0;
            }
        type1=symbolTable.symbols[i+j].type;  //�β�����
        type2=T->ptr[0]->type;
        if (type1!=type2){
            semantic_error(pos,"", "�������Ͳ�ƥ��");
            return 0;
        }
        T=T->ptr[1];
    }
    if (T){ //num�������Ѿ�ƥ���꣬����ʵ�α��ʽ
        semantic_error(pos,"", "�������ò���̫��!");
        return 0;
        }
    return 1;
    }

void boolExp(struct ASTNode *T){  //�������ʽ���ο�����[2]p84��˼��
  struct opn opn1,opn2,result;
  int op;
  int rtn;
  if (T)
	{
	switch (T->kind) {
        case INT:  
                   break;
        case FLOAT: 
                   break;
        case ID:    
                   break;
        case RELOP: //�����ϵ������ʽ,2�������������������ʽ����
                    T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                    Exp(T->ptr[0]);
                    T->width=T->ptr[0]->width;
                    Exp(T->ptr[1]);
                    if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                    opn1.kind=ID; strcpy(opn1.id,symbolTable.symbols[T->ptr[0]->place].alias);
                    opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                    opn2.kind=ID; strcpy(opn2.id,symbolTable.symbols[T->ptr[1]->place].alias);
                    opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
                    result.kind=ID; strcpy(result.id,T->Etrue);
                    if (strcmp(T->type_id,"<")==0)
                            op=JLT;
                    else if (strcmp(T->type_id,"<=")==0)
                            op=JLE;
                    else if (strcmp(T->type_id,">")==0)
                            op=JGT;
                    else if (strcmp(T->type_id,">=")==0)
                            op=JGE;
                    else if (strcmp(T->type_id,"==")==0)
                            op=EQ;
                    else if (strcmp(T->type_id,"!=")==0)
                            op=NEQ;
                    T->code=genIR(op,opn1,opn2,result);
                    T->code=merge(4,T->ptr[0]->code,T->ptr[1]->code,T->code,genGoto(T->Efalse));
                    break;
        case AND: 
        case OR:
                    if (T->kind==AND) {
                        strcpy(T->ptr[0]->Etrue,newLabel());
                        strcpy(T->ptr[0]->Efalse,T->Efalse);
                        }
                    else {
                        strcpy(T->ptr[0]->Etrue,T->Etrue);
                        strcpy(T->ptr[0]->Efalse,newLabel());
                        }
                    strcpy(T->ptr[1]->Etrue,T->Etrue);
                    strcpy(T->ptr[1]->Efalse,T->Efalse);
                    T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                    boolExp(T->ptr[0]);
                    T->width=T->ptr[0]->width;
                    boolExp(T->ptr[1]);
                    if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                    if (T->kind==AND)
                        T->code=merge(3,T->ptr[0]->code,genLabel(T->ptr[0]->Etrue),T->ptr[1]->code);
                    else
                        T->code=merge(3,T->ptr[0]->code,genLabel(T->ptr[0]->Efalse),T->ptr[1]->code);
                    break;
        case NOT:   strcpy(T->ptr[0]->Etrue,T->Efalse);
                    strcpy(T->ptr[0]->Efalse,T->Etrue);
                    boolExp(T->ptr[0]);
                    T->code=T->ptr[0]->code;
                    break;
        }
	}
}


void Exp(struct ASTNode *T)
{//����������ʽ���ο�����[2]p82��˼��
  int rtn,num,width;
  struct ASTNode *T0;
  struct opn opn1,opn2,result;
  if (T)
	{
	switch (T->kind) {
	case ID:    //����ű���÷��ű��е�λ�ã�������type
                rtn=searchSymbolTable(T->type_id);
                if (rtn==-1)
                    semantic_error(T->pos,T->type_id, "����δ����");
                if (symbolTable.symbols[rtn].flag=='F')
                    semantic_error(T->pos,T->type_id, "�Ǻ����������Ͳ�ƥ��");
                else {
                    T->place=rtn;       //��㱣������ڷ��ű��е�λ��
                    T->code=NULL;       //��ʶ������Ҫ����TAC
                    T->type=symbolTable.symbols[rtn].type;
                    T->offset=symbolTable.symbols[rtn].offset;
                    T->width=0;   //δ��ʹ���µ�Ԫ
                    }
                break;
    case INT:   T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset); //Ϊ����������һ����ʱ����
                T->type=INT;
                opn1.kind=INT;opn1.const_int=T->type_int;
                result.kind=ID; strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=genIR(ASSIGNOP,opn1,opn2,result);
                T->width=4;
                break;
    case FLOAT: T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset);   //Ϊ���㳣������һ����ʱ����
                T->type=FLOAT;
                opn1.kind=FLOAT; opn1.const_float=T->type_float;
                result.kind=ID; strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=genIR(ASSIGNOP,opn1,opn2,result);
                T->width=4;
                break;
	case ASSIGNOP:
                if (T->ptr[0]->kind!=ID){
                    semantic_error(T->pos,"", "��ֵ�����Ҫ��ֵ");
                    }
                else {
                    Exp(T->ptr[0]);   //������ֵ�����н�Ϊ����
                    T->ptr[1]->offset=T->offset;
                    Exp(T->ptr[1]);
                    T->type=T->ptr[0]->type;
                    T->width=T->ptr[1]->width;
                    T->code=merge(2,T->ptr[0]->code,T->ptr[1]->code);
                    opn1.kind=ID;   strcpy(opn1.id,symbolTable.symbols[T->ptr[1]->place].alias);//��ֵһ���Ǹ���������ʱ����
                    opn1.offset=symbolTable.symbols[T->ptr[1]->place].offset;
                    result.kind=ID; strcpy(result.id,symbolTable.symbols[T->ptr[0]->place].alias);
                    result.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                    T->code=merge(2,T->code,genIR(ASSIGNOP,opn1,opn2,result));
                    }
                break;
	case AND:   //���������ʽ��ʽ���㲼��ֵ��δд��
	case OR:    //���������ʽ��ʽ���㲼��ֵ��δд��
	case RELOP: //���������ʽ��ʽ���㲼��ֵ��δд��
                T->type=INT;
                T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                Exp(T->ptr[0]);
                Exp(T->ptr[1]);
                break;
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:   T->ptr[0]->offset=T->offset;
                Exp(T->ptr[0]);
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                Exp(T->ptr[1]);
                //�ж�T->ptr[0]��T->ptr[1]�����Ƿ���ȷ�����ܸ�����������ɲ�ͬ��ʽ�Ĵ��룬��T��type��ֵ
                //������������Լ��㣬û�п��Ǵ��������
                if (T->ptr[0]->type==FLOAT || T->ptr[1]->type==FLOAT)
                     T->type=FLOAT,T->width=T->ptr[0]->width+T->ptr[1]->width+4;
                else T->type=INT,T->width=T->ptr[0]->width+T->ptr[1]->width+2;
                T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset+T->ptr[0]->width+T->ptr[1]->width);
                opn1.kind=ID; strcpy(opn1.id,symbolTable.symbols[T->ptr[0]->place].alias);
                opn1.type=T->ptr[0]->type;opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                opn2.kind=ID; strcpy(opn2.id,symbolTable.symbols[T->ptr[1]->place].alias);
                opn2.type=T->ptr[1]->type;opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
                result.kind=ID; strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.type=T->type;result.offset=symbolTable.symbols[T->place].offset;
                T->code=merge(3,T->ptr[0]->code,T->ptr[1]->code,genIR(T->kind,opn1,opn2,result));
                T->width=T->ptr[0]->width+T->ptr[1]->width+(T->type==INT?4:8);
                break;
	case NOT:   //δд����
                break;
	case UMINUS://δд����
                break;
    case FUNC_CALL: //����T->type_id��������Ķ��壬���������������ʵ��̲ĵ�read��write��Ҫ��������һ��
                rtn=searchSymbolTable(T->type_id);
                if (rtn==-1){
                    semantic_error(T->pos,T->type_id, "����δ����");
                    break;
                    }
                if (symbolTable.symbols[rtn].flag!='F'){
                    semantic_error(T->pos,T->type_id, "����һ������");
                     break;
                    }
                T->type=symbolTable.symbols[rtn].type;
                width=T->type==INT?4:8;   //��ź�������ֵ�ĵ����ֽ���
                if (T->ptr[0]){
                    T->ptr[0]->offset=T->offset;
                    Exp(T->ptr[0]);       //��������ʵ�α��ʽ��ֵ��������
                    T->width=T->ptr[0]->width+width; //�ۼ��ϼ���ʵ��ʹ����ʱ�����ĵ�Ԫ��
                    T->code=T->ptr[0]->code;
                    }
                else {T->width=width; T->code=NULL;}
                match_param(rtn,T);   //�������в�����ƥ��
                    //��������б���м����
                T0=T->ptr[0];
                while (T0) {
                    result.kind=ID;  strcpy(result.id,symbolTable.symbols[T0->ptr[0]->place].alias);
                    result.offset=symbolTable.symbols[T0->ptr[0]->place].offset;
                    T->code=merge(2,T->code,genIR(ARG,opn1,opn2,result));
                    T0=T0->ptr[1];
                    }
                T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset+T->width-width);
                opn1.kind=ID;     strcpy(opn1.id,T->type_id);  //���溯����
                opn1.offset=rtn;  //����offset���Ա��溯���������,��Ŀ���������ʱ���ܻ�ȡ��Ӧ��Ϣ
                result.kind=ID;   strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=merge(2,T->code,genIR(CALL,opn1,opn2,result)); //���ɺ��������м����
                break;
    case ARGS:      //�˴��������ʵ�α��ʽ����ֵ�Ĵ������У�������ARG��ʵ��ϵ��
                T->ptr[0]->offset=T->offset;
                Exp(T->ptr[0]);
                T->width=T->ptr[0]->width;
                T->code=T->ptr[0]->code;
                if (T->ptr[1]) {
                    T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                    Exp(T->ptr[1]);
                    T->width+=T->ptr[1]->width;
                    T->code=merge(2,T->code,T->ptr[1]->code);
                    }
                break;
         }
      }
}

void semantic_Analysis(struct ASTNode *T)
{//�Գ����﷨�����ȸ�����,��display�Ŀ��ƽṹ�޸���ɷ��ű������������TAC���ɣ���䲿�֣�
  int rtn,num,width;
  struct ASTNode *T0;
  struct opn opn1,opn2,result;
  if (T)
	{
	switch (T->kind) {
	case EXT_DEF_LIST:
            if (!T->ptr[0]) break;
            T->ptr[0]->offset=T->offset;
            semantic_Analysis(T->ptr[0]);    //�����ⲿ�����б��еĵ�һ��
            T->code=T->ptr[0]->code;
            if (T->ptr[1]){
                T->ptr[1]->offset=T->ptr[0]->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]); //���ʸ��ⲿ�����б��е������ⲿ����
                T->code=merge(2,T->code,T->ptr[1]->code);
                }
            break;
	case EXT_VAR_DEF:   //�����ⲿ˵��,����һ������(TYPE���)�е������͵��ڶ������ӵ�������
            T->type=T->ptr[1]->type=!strcmp(T->ptr[0]->type_id,"int")?INT: !strcmp(T->ptr[0]->type_id, "bool")?BOOL:STRING;
            T->ptr[1]->offset=T->offset;        //����ⲿ������ƫ�������´���
            T->ptr[1]->width=T->type==INT?4:8;  //��һ�������Ŀ�����´���
            ext_var_list(T->ptr[1]);            //�����ⲿ����˵���еı�ʶ������
            T->width=(T->type==INT?4:8)* T->ptr[1]->num; //��������ⲿ����˵���Ŀ��
            T->code=NULL;             //����ٶ��ⲿ������֧�ֳ�ʼ��
            break;
	case FUNC_DEF:      //��д����������Ϣ�����ű�
            T->ptr[1]->type=!strcmp(T->ptr[0]->type_id,"int")?INT: strcmp(T->ptr[0]->type_id, "bool") ?BOOL:STRING ;//��ȡ�������������͵����������������Ľ��
            T->width=0;     //�����Ŀ������Ϊ0��������ⲿ�����ĵ�ַ�������Ӱ��
            T->offset=DX;   //���þֲ������ڻ��¼�е�ƫ������ֵ
            semantic_Analysis(T->ptr[1]); //���������Ͳ�����㲿�֣����ﲻ�����üĴ������ݲ���
            T->offset+=T->ptr[1]->width;   //���βε�Ԫ����޸ĺ����ֲ���������ʼƫ����
            T->ptr[2]->offset=T->offset;
            strcpy(T->ptr[2]->Snext,newLabel());  //���������ִ�н������λ������
            semantic_Analysis(T->ptr[2]);         //����������
            //������¼��С,����offset���Դ�ŵ��ǻ��¼��С������ƫ��
            symbolTable.symbols[T->ptr[1]->place].offset=T->offset+T->ptr[2]->width;
            T->code=merge(3,T->ptr[1]->code,T->ptr[2]->code,genLabel(T->ptr[2]->Snext));          //������Ĵ�����Ϊ�����Ĵ���
            break;
	case FUNC_DEC:      //���ݷ������ͣ���������д���ű�
            rtn=fillSymbolTable(T->type_id,newAlias(),LEV,T->type,'F',0);//���������������з��䵥Ԫ��ƫ����Ϊ0
            if (rtn==-1){
                semantic_error(T->pos,T->type_id, "�����ظ�����");
                break;
                }
            else T->place=rtn;
            result.kind=ID;   strcpy(result.id,T->type_id);
            result.offset=rtn;
            T->code=genIR(FUNCTION,opn1,opn2,result);     //�����м���룺FUNCTION ������
            T->offset=DX;   //������ʽ�����ڻ��¼�е�ƫ������ֵ
            if (T->ptr[0]) { //�ж��Ƿ��в���
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);  //�����������б�
                T->width=T->ptr[0]->width;
                symbolTable.symbols[rtn].paramnum=T->ptr[0]->num;
                T->code=merge(2,T->code,T->ptr[0]->code);  //���Ӻ������Ͳ�����������
                }
            else symbolTable.symbols[rtn].paramnum=0,T->width=0;
            break;
	case PARAM_LIST:    //��������ʽ�����б�
            T->ptr[0]->offset=T->offset;
            semantic_Analysis(T->ptr[0]);
            if (T->ptr[1]){
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]);
                T->num=T->ptr[0]->num+T->ptr[1]->num;        //ͳ�Ʋ�������
                T->width=T->ptr[0]->width+T->ptr[1]->width;  //�ۼӲ�����Ԫ���
                T->code=merge(2,T->ptr[0]->code,T->ptr[1]->code);  //���Ӳ�������
                }
            else {
                T->num=T->ptr[0]->num;
                T->width=T->ptr[0]->width;
                T->code=T->ptr[0]->code;
                }
            break;
	case  PARAM_DEC:
            rtn=fillSymbolTable(T->ptr[1]->type_id,newAlias(),1,T->ptr[0]->type,'P',T->offset);
            if (rtn==-1)
                semantic_error(T->ptr[1]->pos,T->ptr[1]->type_id, "�������ظ�����");
            else T->ptr[1]->place=rtn;
            T->num=1;       //������������ĳ�ʼֵ
            T->width=T->ptr[0]->type==INT?4:8;  //�������
            result.kind=ID;   strcpy(result.id, symbolTable.symbols[rtn].alias);
            result.offset=T->offset;
            T->code=genIR(PARAM,opn1,opn2,result);     //���ɣ�FUNCTION ������
            break;
	case COMP_STM:
            LEV++;
            //���ò�ż�1�����ұ���ò�ֲ������ڷ��ű��е���ʼλ����symbol_scope_TX
            symbol_scope_TX.TX[symbol_scope_TX.top++]=symbolTable.index;
            T->width=0;
            T->code=NULL;
            if (T->ptr[0]) {
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);  //����ò�ľֲ�����DEF_LIST
                T->width+=T->ptr[0]->width;
                T->code=T->ptr[0]->code;
                }
            if (T->ptr[1]){
                T->ptr[1]->offset=T->offset+T->width;
                strcpy(T->ptr[1]->Snext,T->Snext);  //S.next�������´���
                semantic_Analysis(T->ptr[1]);       //�����������������
                T->width+=T->ptr[1]->width;
                T->code=merge(2,T->code,T->ptr[1]->code);
                }
             #if (DEBUG)
               // prn_symbol();       //c���˳�һ���������ǰ��ʾ�ķ��ű�
			 // system("pause");
             #endif
             LEV--;    //��������䣬��ż�1
             symbolTable.index=symbol_scope_TX.TX[--symbol_scope_TX.top]; //ɾ�����������еķ���
             break;
    case DEF_LIST:
            T->code=NULL;
            if (T->ptr[0]){
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);   //����һ���ֲ���������
                T->code=T->ptr[0]->code;
                T->width=T->ptr[0]->width;
                }
            if (T->ptr[1]) {
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]);   //����ʣ�µľֲ���������
                T->code=merge(2,T->code,T->ptr[1]->code);
                T->width+=T->ptr[1]->width;
                }
                break;
    case VAR_DEF://����һ���ֲ���������,����һ������(TYPE���)�е������͵��ڶ������ӵ�������
                 //������������ⲿ����EXT_VAR_DEF������һ�ִ�����
                T->code=NULL;
                T->ptr[1]->type=!strcmp(T->ptr[0]->type_id,"int")?INT:FLOAT;  //ȷ���������и���������
                T0=T->ptr[1]; //T0Ϊ�������б�������ָ�룬��ID��ASSIGNOP�����ڵǼǵ����ű���Ϊ�ֲ�����
                num=0;
                T0->offset=T->offset;
                T->width=0;
                width=T->ptr[1]->type==INT?4:8;  //һ���������
                while (T0) {  //��������DEC_LIST���
                    num++;
                    T0->ptr[0]->type=T0->type;  //�����������´���
                    if (T0->ptr[1]) T0->ptr[1]->type=T0->type;
                    T0->ptr[0]->offset=T0->offset;  //�����������´���
                    if (T0->ptr[1]) T0->ptr[1]->offset=T0->offset+width;
                    if (T0->ptr[0]->kind==ID){
                        rtn=fillSymbolTable(T0->ptr[0]->type_id,newAlias(),LEV,T0->ptr[0]->type,'V',T->offset+T->width);//�˴�ƫ����δ���㣬��ʱΪ0
                        if (rtn==-1)
                            semantic_error(T0->ptr[0]->pos,T0->ptr[0]->type_id, "�����ظ�����");
                        else T0->ptr[0]->place=rtn;
                        T->width+=width;
                        }
                    else if (T0->ptr[0]->kind==ASSIGNOP){
                            rtn=fillSymbolTable(T0->ptr[0]->ptr[0]->type_id,newAlias(),LEV,T0->ptr[0]->type,'V',T->offset+T->width);//�˴�ƫ����δ���㣬��ʱΪ0
                            if (rtn==-1)
                                semantic_error(T0->ptr[0]->ptr[0]->pos,T0->ptr[0]->ptr[0]->type_id, "�����ظ�����");
                            else {
                                T0->ptr[0]->place=rtn;
                                T0->ptr[0]->ptr[1]->offset=T->offset+T->width+width;
                                Exp(T0->ptr[0]->ptr[1]);
                                opn1.kind=ID; strcpy(opn1.id,symbolTable.symbols[T0->ptr[0]->ptr[1]->place].alias);
                                result.kind=ID; strcpy(result.id,symbolTable.symbols[T0->ptr[0]->place].alias);
                                T->code=merge(3,T->code,T0->ptr[0]->ptr[1]->code,genIR(ASSIGNOP,opn1,opn2,result));
                                }
                            T->width+=width+T0->ptr[0]->ptr[1]->width;
                            }
                    T0=T0->ptr[1];
                    }
                break;
	case STM_LIST:
                if (!T->ptr[0]) { T->code=NULL; T->width=0; break;}   //���������
                if (T->ptr[1]) //2������������ӣ������±����Ϊ��һ���������󵽴��λ��
                    strcpy(T->ptr[0]->Snext,newLabel());
                else     //������н���һ����䣬S.next�������´���
                    strcpy(T->ptr[0]->Snext,T->Snext);
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);
                T->code=T->ptr[0]->code;
                T->width=T->ptr[0]->width;
                if (T->ptr[1]){     //2�������������,S.next�������´���
                    strcpy(T->ptr[1]->Snext,T->Snext);
                    T->ptr[1]->offset=T->offset;  //˳��ṹ����Ԫ��ʽ
//                  T->ptr[1]->offset=T->offset+T->ptr[0]->width; //˳��ṹ˳����䵥Ԫ��ʽ
                    semantic_Analysis(T->ptr[1]);
                    //�����е�1��Ϊ���ʽ��䣬������䣬�������ʱ����2��ǰ����Ҫ���
                    if (T->ptr[0]->kind==RETURN ||T->ptr[0]->kind==EXP_STMT ||T->ptr[0]->kind==COMP_STM)
                        T->code=merge(2,T->code,T->ptr[1]->code);
                    else
                        T->code=merge(3,T->code,genLabel(T->ptr[0]->Snext),T->ptr[1]->code);
                    if (T->ptr[1]->width>T->width) T->width=T->ptr[1]->width; //˳��ṹ����Ԫ��ʽ
//                        T->width+=T->ptr[1]->width;//˳��ṹ˳����䵥Ԫ��ʽ
                    }
                break;
	case IF_THEN:
                strcpy(T->ptr[0]->Etrue,newLabel());  //��������������ת��λ��
                strcpy(T->ptr[0]->Efalse,T->Snext);
                T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                boolExp(T->ptr[0]);
                T->width=T->ptr[0]->width;
                strcpy(T->ptr[1]->Snext,T->Snext);
                semantic_Analysis(T->ptr[1]);      //if�Ӿ�
                if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                T->code=merge(3,T->ptr[0]->code, genLabel(T->ptr[0]->Etrue),T->ptr[1]->code);
                break;  //������䶼��û�д���offset��width����
	case IF_THEN_ELSE:
                strcpy(T->ptr[0]->Etrue,newLabel());  //��������������ת��λ��
                strcpy(T->ptr[0]->Efalse,newLabel());
                T->ptr[0]->offset=T->ptr[1]->offset=T->ptr[2]->offset=T->offset;
                boolExp(T->ptr[0]);      //������Ҫ��������·���봦��
                T->width=T->ptr[0]->width;
                strcpy(T->ptr[1]->Snext,T->Snext);
                semantic_Analysis(T->ptr[1]);      //if�Ӿ�
                if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                strcpy(T->ptr[2]->Snext,T->Snext);
                semantic_Analysis(T->ptr[2]);      //else�Ӿ�
                if (T->width<T->ptr[2]->width) T->width=T->ptr[2]->width;
                T->code=merge(6,T->ptr[0]->code,genLabel(T->ptr[0]->Etrue),T->ptr[1]->code,\
                              genGoto(T->Snext),genLabel(T->ptr[0]->Efalse),T->ptr[2]->code);
                break;
	case WHILE: strcpy(T->ptr[0]->Etrue,newLabel());  //�ӽ��̳����Եļ���
                strcpy(T->ptr[0]->Efalse,T->Snext);
                T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                boolExp(T->ptr[0]);      //ѭ��������Ҫ��������·���봦��
                T->width=T->ptr[0]->width;
                strcpy(T->ptr[1]->Snext,newLabel());
                semantic_Analysis(T->ptr[1]);      //ѭ����
                if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                T->code=merge(5,genLabel(T->ptr[1]->Snext),T->ptr[0]->code, \
                genLabel(T->ptr[0]->Etrue),T->ptr[1]->code,genGoto(T->ptr[1]->Snext));
                break;
    case EXP_STMT:
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);
                T->code=T->ptr[0]->code;
                T->width=T->ptr[0]->width;
                break;
	case RETURN:if (T->ptr[0]){
                    T->ptr[0]->offset=T->offset;
                    Exp(T->ptr[0]);

				 /*��Ҫ�жϷ���ֵ�����Ƿ�ƥ��*/

                    T->width=T->ptr[0]->width;
                    result.kind=ID; strcpy(result.id,symbolTable.symbols[T->ptr[0]->place].alias);
                    result.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                    T->code=merge(2,T->ptr[0]->code,genIR(RETURN,opn1,opn2,result));
                    }
                else{
                    T->width=0;
                    result.kind=0;
                    T->code=genIR(RETURN,opn1,opn2,result);
                    }
                break;
	case ID:
    case INT:
    case FLOAT:
	case ASSIGNOP:
	case AND:
	case OR:
	case RELOP:
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:
	case NOT:
	case UMINUS:
    case FUNC_CALL:
                    Exp(T);          //����������ʽ
                    break;
    }
    }
}

void semantic_Analysis0(struct ASTNode *T) {
    symbolTable.index=0;
    fillSymbolTable("read","",0,INT,'F',4);
    symbolTable.symbols[0].paramnum=0;//read���βθ���
    fillSymbolTable("write","",0,INT,'F',4);
    symbolTable.symbols[1].paramnum=1;
    fillSymbolTable("x","",1,INT,'P',12);
    symbol_scope_TX.TX[0]=0;  //�ⲿ�����ڷ��ű��е���ʼ���Ϊ0
    symbol_scope_TX.top=1;
    T->offset=0;              //�ⲿ��������������ƫ����
    semantic_Analysis(T);
   // prnIR(T->code);
    //objectCode(T->code);
 } 