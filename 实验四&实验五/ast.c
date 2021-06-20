#include "def.h"
#include "parser.tab.h"
#define OFFSET 3

struct ASTNode * mknode(int num,int kind,int pos,...){
    struct ASTNode *T=(struct ASTNode *)calloc(sizeof(struct ASTNode),1);
    int i=0;
    T->kind=kind;
    T->pos=pos;
    va_list pArgs;
    va_start(pArgs, pos);
    for(i=0;i<num;i++)
        T->ptr[i]= va_arg(pArgs, struct ASTNode *);
    while (i<4) T->ptr[i++]=NULL;
    va_end(pArgs);
    return T;
}

void displayRoot(){
    printf("Program Root���ڵ�\n");
}
void display(struct ASTNode *T,int indent)
{//�Գ����﷨�����ȸ�����
  int i=1;
  struct ASTNode *T0;
  char* type;
  if (T)
	{
    switch (T->kind)
    {
	case EXT_DEF_LIST:  
        display(T->ptr[0],indent);    //��ʾ���ⲿ���壨�ⲿ�����ͺ������б��еĵ�һ��
        display(T->ptr[1],indent);    //��ʾ���ⲿ�����б��е������ⲿ����
        break;
	case EXT_VAR_DEF:   
        printf("%*c�ⲿ�������壺(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);        //��ʾ�ⲿ��������
        printf("%*c��������\n",indent+OFFSET,' ');
        display(T->ptr[1],indent+OFFSET*2);        //��ʾ�����б�
        break;
    case TYPE:         
        printf("%*c���ͣ� %s\n",indent,' ',T->type_id);
        break;
    case EXT_DEC_LIST:  
        display(T->ptr[0],indent);     //������ʾ�ⲿ��������
        display(T->ptr[1],indent);     //����������ͬ�ģ�����ʾ�﷨���˴��������Ժ����ƴ���ϲ�
        break;
	case FUNC_DEF:      
        printf("%*c�������壺(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);      //��ʾ������������
        display(T->ptr[1],indent+OFFSET);      //��ʾ�������Ͳ���
        display(T->ptr[2],indent+OFFSET);      //��ʾ������
        break;
	case FUNC_DEC:      
        printf("%*c��������%s\n",indent,' ',T->type_id);
        if (T->ptr[0])
        {
            printf("%*c�����βΣ�\n",indent,' ');
            display(T->ptr[0],indent+OFFSET);  //��ʾ���������б�
        }
        else printf("%*c�޲κ���\n",indent+OFFSET,' ');
        break;
	case PARAM_LIST:    
        display(T->ptr[0],indent);     //������ʾȫ���������ͺ����ƣ�
        display(T->ptr[1],indent);
        break;
	case PARAM_DEC:
        
        switch (T->ptr[0]->type)
        {
        case INT:
            strcpy(type,"int");
            break;
        case FLOAT:
            strcpy(type, "float");
            break;
        case BOOL:
            strcpy(type, "bool");
            break;
        case STRING:
            strcpy(type, "string");
        default:
            strcpy(type, "char");
            break;
        }
        printf("%*c���ͣ�%s, ��������%s\n",indent,' ',type,T->ptr[1]->type_id);
        break;
	case EXP_STMT:      
        printf("%*c���ʽ��䣺(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);
        break;
	case RETURN:        
        printf("%*c������䣺(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);
        break;
	case COMP_STM:      
        printf("%*c������䣺(%d)\n",indent,' ',T->pos);
        printf("%*c�������ı������岿�֣�\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //��ʾ���岿��
        printf("%*c����������䲿�֣�\n",indent+OFFSET,' ');
        display(T->ptr[1],indent+OFFSET*2);      //��ʾ��䲿��
        break;
	case STM_LIST:      
        display(T->ptr[0],indent);      //��ʾ��һ�����
        display(T->ptr[1],indent);        //��ʾʣ�����
        break;
	case WHILE:         
        printf("%*cWHILEѭ��(���)��(%d)\n",indent,' ',T->pos);
        printf("%*cѭ��������\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //��ʾѭ������
        printf("%*cѭ���壺(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1],indent+OFFSET*2);      //��ʾѭ����
        break;
	case IF_THEN:       
        printf("%*c�������(IF_THEN)��(%d)\n",indent,' ',T->pos);
        printf("%*c������\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //��ʾ����
        printf("%*cIF�Ӿ䣺(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1],indent+OFFSET*2);      //��ʾif�Ӿ�
        break;
	case IF_THEN_ELSE:  
        printf("%*c�������(IF_THEN_ELSE)��(%d)\n",indent,' ',T->pos);
        printf("%*c������\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //��ʾ����
        printf("%*cIF�Ӿ䣺(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1],indent+OFFSET*2);      //��ʾif�Ӿ�
        printf("%*cELSE�Ӿ䣺(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[2],indent+OFFSET*2);      //��ʾelse�Ӿ�
        break;
    case DEF_LIST:     
        display(T->ptr[0],indent);    //��ʾ�þֲ����������б��еĵ�һ��
        display(T->ptr[1],indent);    //��ʾ�����ֲ���������
        break;
    case VAR_DEF:       
        printf("%*c�ֲ��������壺(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);   //��ʾ��������
        display(T->ptr[1],indent+OFFSET);   //��ʾ�ö����ȫ��������
        break;
    case DEC_LIST:      
        printf("%*c��������\n",indent,' ');
        T0=T;
        while (T0) {
            if (T0->ptr[0]->kind==ID){
                 printf("%*c %s\n",indent+OFFSET*2,' ',T0->ptr[0]->type_id);
            }
            else if (T0->ptr[0]->kind==ASSIGNOP)
            {
                if(T0->ptr[0]->ptr[0]->kind == ARRAY_DF) display(T0->ptr[0]->ptr[0],indent); //var_dec assignop exp�����
                printf("%*c %s ��ֵ���\n ",indent+OFFSET*2,' ',T0->ptr[0]->ptr[0]->type_id);
                display(T0->ptr[0]->ptr[1],indent+strlen(T0->ptr[0]->ptr[0]->type_id)+7);        //��ʾ��ʼ�����ʽ
                
            }
            else if(T0->ptr[0]->kind==ARRAY_DF){
                printf("%*c ����%s\n",indent+OFFSET*2,' ',T0->ptr[0]->type_id);//var $$=$1
            }

            T0=T0->ptr[1];
        }
        break;
    case ID:	        
        printf("%*cID�� %s\n",indent,' ',T->type_id);
        break;
    case CONTINUE:
	    printf("%*c CONTINUE���(%d)\n", indent, ' ', T->pos);
	    break;
	case BREAK:
	    printf("%*c BREAK���(%d)\n", indent, ' ', T->pos);
	    break;
    //����Ĵ�ӡ
    case ARRAY_DF:
        printf("%*c ���� %s", indent, ' ', T->type_id);
        display(T->ptr[0], indent + 3);
        printf("\n");
        break;
    case ARRAY_DEC:
        if (T->ptr[0])
            printf("[%d]", T->ptr[0]->type_int);
        display(T->ptr[1], 0);
        break;
    case ARRAY_CALL:
        printf("%*c������ %s\n",indent,' ',T->type_id);
        printf("%*c  �����±�:", indent, ' ');
        display(T->ptr[0], 0);
        break;
	case INT:	     
        printf("%*cINT ���ͳ�����%d\n",indent,' ',T->type_int);
        break;
	case FLOAT:	        
        printf("%*cFLAOT �����ͳ�����%f\n",indent,' ',T->type_float);
        break;
    case CHAR:
        printf("%*cCHAR ���ַ�����: %c\n", indent, ' ', T->type_char);
        break;
    case BOOL:
        printf("%*cBOOL ��������: %s\n", indent, ' ', T->type_bool);
        break;
    case STRING:
        printf("%*cSTRING �ַ�������: %s\n", indent, ' ', T->type_string);//STRING
        break;
	case ASSIGNOP:
        T0 = T;
        if (T0->ptr[0]->kind == ARRAY_DF) {
            printf("%*c ���� %s", indent, ' ', T->type_id);
            display(T0->ptr[0]->ptr[0], indent + 3);
            printf("\n");
        }
    case PLUSASSIGNOP:
    case MINUSASSIGNOP:
    case STARASSIGNOP:
    case DIVASSIGNOP:
    case MODASSIGNOP:
	case AND:
	case OR:
	case RELOP:
	case PLUS:
    case AUTOPLUS:
    case AUTOMINUS:
	case MINUS:
	case STAR:
	case DIV:
    case MOD:
        printf("%*c%s\n",indent,' ',T->type_id);
        display(T->ptr[0],indent+OFFSET);
        display(T->ptr[1],indent+OFFSET);
        break;
	case NOT:
	case UMINUS:    
        printf("%*c%s\n",indent,' ',T->type_id);
        display(T->ptr[0],indent+OFFSET);
        break;
    case FUNC_CALL: 
        printf("%*c�������ã�(%d)\n",indent,' ',T->pos);
        printf("%*c��������%s\n",indent+OFFSET,' ',T->type_id);
        display(T->ptr[0],indent+OFFSET);
        break;
	case ARGS:      
        i=1;
        while (T) {  //ARGS��ʾʵ�ʲ������ʽ���н�㣬���һ������Ϊ��һ��ʵ�ʲ������ʽ���ڶ�������Ϊʣ�µ�
            struct ASTNode *T0=T->ptr[0];
            printf("%*c��%d����\n",indent,' ',i++);
            display(T0,indent+OFFSET);
            T=T->ptr[1];
        }
//      printf("%*c��%d��ʵ�ʲ������ʽ��\n",indent,' ',i);
  //    display(T,indent+OFFSET);
        printf("\n");
        break;
    case SWITCH:
        printf("%*cSwitch���:(%d)\n", indent, ' ',T->pos);
        printf("%*c�ж϶���:\n", indent+3, ' ');
        display(T->ptr[0], indent+6);
        display(T->ptr[1],indent+6);
        break;
    case CASE_STMT_LIST:
        display(T->ptr[0], indent);
        display(T->ptr[1], indent);
        break;
    case CASE_STMT:
        printf("%*cCase���:\n", indent, ' ');
        printf("%*cƥ��ֵ:\n", indent+3, ' ');
        if (T->type == CHAR){
            printf("%*cCHAR��'%c'\n", indent+6, ' ', T->type_char);
        } else if (T->type == INT) {
            printf("%*cINT��%d\n", indent+6, ' ', T->type_int);
        }
        printf("%*cCase����:\n", indent+3, ' ');
        display(T->ptr[0], indent+6);
        break;
    case DEFAULT_STMT:
        printf("%*cDefualt���:\n", indent, ' ');
        printf("%*cDefault����:\n", indent+3, ' ');
        display(T->ptr[0], indent+6);
        break;
    case STRUCT_NEW:
        printf("%*c����ṹ��:\n", indent, ' ');
        display(T->ptr[0], indent+6);
        printf("%*c�ṹ���Ա:\n", indent, ' ');
        display(T->ptr[1], indent+6);
        break;
    case STRUCT_DEC:
        printf("%*c�½��ṹ�����:\n", indent, ' ');
        printf("%*c   ������:%s\n", indent, ' ', T->type_id);
        break;
    case EXT_STRUCT_DEC:
        printf("%*c�ⲿ�ṹ��:\n", indent, ' ');
        display(T->ptr[0], indent+3);
        break;
    case STRUCT_VISIT:
        printf("%*c���ʶ���:\n", indent, ' ');
        display(T->ptr[0], indent+3);
        printf("%*cĿ��Ԫ��:\n", indent, ' ');
        printf("%*cID: %s\n",indent+3, ' ', T->type_id);
        break;
    case FOR:
        printf("%*cFor(ѭ��)��(%d)\n", indent, ' ', T->pos);
        printf("%*cѭ��������\n", indent + 3, ' ');
        display(T->ptr[0], indent + 6); //��ʾѭ������
        printf("%*cѭ���壺(%d)\n", indent + 3, ' ', T->pos);
        display(T->ptr[1], indent + 6); //��ʾѭ����
        break;
    case FOR_DEC:
        display(T->ptr[0], indent + 6);
        display(T->ptr[1], indent + 6);
        display(T->ptr[2], indent + 6);
        break;
    case FOR_EXP1:
        printf("%*cѭ����ʼ���(%d)\n", indent, ' ', T->pos);
        display(T->ptr[0], indent + 3);
        display(T->ptr[1], indent + 3);
        break;
    case FOR_EXP2:
        printf("%*cѭ���������(%d)\n", indent, ' ', T->pos);
        display(T->ptr[0], indent + 3);
        break;
    case FOR_EXP3:
        printf("%*cѭ����������(%d)\n", indent, ' ', T->pos);
        while (T)
        {
            struct ASTNode *T0 = T->ptr[0];
            display(T0, indent + 3);
            T = T->ptr[1];
        }
        break;
    default:
        printf("δ�ҵ�������\n");
        break;
        }
    }
}