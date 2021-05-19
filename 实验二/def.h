#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "parser.tab.h"
#define MAXLENGTH   200
#define DX 3*sizeof(int)          /*���¼������Ϣ��Ҫ�ĵ�Ԫ�����������ʵ��ϵͳ����*/
//�����﷨��������͡�����ַ������͵ȶ�������ο���ʵ��ʱһ��Ҫ�����Լ������������
int LEV;      //���
struct opn{
    int kind;    //��ʶ���ϳ�Ա������
    int type;    //��ʶ����������������
    union {
        int     const_int;      //������ֵ��������
        float   const_float;    //���㳣��ֵ��������
        char    const_char;     //�ַ�����ֵ��������
        char    const_bool[5];
        char    const_string[1024];
        char    id[33];         //��������ʱ�����ı��������ַ���
        };
    int level;                  //�����Ĳ�ţ�0��ʾ��ȫ�ֱ��������ݱ����ھ�̬������
    int offset;                 //ƫ������Ŀ���������ʱ��
    };

struct codenode {   //����ַTAC������,���õ��������м����Դ���
        int  op;
        struct opn opn1,opn2,result;
        struct codenode  *next,*prior;
    };

struct ASTNode {
        //���¶Խ�����Զ���û�п��Ǵ洢Ч�ʣ�ֻ�Ǽ򵥵��г�Ҫ�õ���һЩ����
	int kind;
	union {
		  char type_id[33];             //�ɱ�ʶ�����ɵ�Ҷ���
		  int type_int;                 //�����������ɵ�Ҷ���
		  float type_float;               //�ɸ��㳣�����ɵ�Ҷ���
          char type_bool[5];
          char type_string[1024];
	      };
    struct ASTNode *ptr[4];         //��kindȷ���ж��ٿ�����
    int place;                     //��ţ���ʱ�������ڷ��ű��λ�����
    char Etrue[15],Efalse[15];       //�Բ������ʽ�ķ���ʱ�����ת��Ŀ��ı��
    char Snext[15];               //����Ӧ���Sִ�к����һ�����λ�ñ��
    struct codenode *code;          //�ý���м��������ͷָ��
    int type;                      //���Ա�ʶ���ʽ��������
    int pos;                       //�﷨��λ����λ���к�
    int offset;                     //ƫ����
    int width;                     //ռ�����ֽ���
    int num;                      //����������������ͳ���βθ���
    };

struct symbol {       //����ֻ�г���һ�����ű���Ĳ������ԣ�û�������Լ�Ļ���
    char name[33];   //����������
    int level;        //���
    int type;         //�������ͻ�������ֵ����
    int  paramnum;  //�Ժ������ã���¼��ʽ��������
    char alias[10];   //������Ϊ���Ƕ�ײ��ʹ��
    char flag;       //���ű�ǣ�������'F'  ������'V'   ������'P'  ��ʱ������'T'
char offset;      //�ⲿ�����;ֲ��������侲̬����������¼�е�ƫ������
//���¼�������¼��С��Ŀ���������ʱʹ��
    //������ڵ�ʵ����ܻ��õ�������...
    };
//���ű�
struct symboltable{
    struct symbol symbols[MAXLENGTH];
    int index;
    } symbolTable;

struct symbol_scope_begin {
    //��ǰ������ķ����ڷ��ű����ʼλ�����,����һ��ջ�ṹ,��ʹ��˳�����Ϊ���ű�ʱ�����롢�˳�һ��������ʱ��Ҫ�������������ɷ��ű�Ĺ�����������ʽ�ķ��ű���һ����Ҫ�����ݽṹ
    int TX[30];
    int top;
    } symbol_scope_TX;


struct ASTNode * mknode(int num,int kind,int pos,...);
void semantic_Analysis0(struct ASTNode *T);
void semantic_Analysis(struct ASTNode *T);
void boolExp(struct ASTNode *T);
void Exp(struct ASTNode *T);
void objectCode(struct codenode *head);