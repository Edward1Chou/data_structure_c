#include <stdio.h>
#include <malloc.h>

typedef int SElemType;
typedef int Status;
#define INIT_SIZE 100
#define STACKINCREMENT 10
#define Ok 1
#define Error 0
#define True 1
#define False 0
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

//��ʼ��ջ
Status InitStack(SqStack *s)
{
    s->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
    if(!s->base)
    {
        puts("�洢�ռ����ʧ�ܣ�");
        return Error;
    }
    s->top = s->base;
    s->stacksize = INIT_SIZE;
    return Ok;
}

//���ջ
Status ClearStack(SqStack *s)
 {
   s->top = s->base;
   return Ok;
 }

//ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack *s)
 {
   if(s->top == s->base)
     return True;
   else
     return False;
 }

//����ջ
Status Destroy(SqStack *s)
{
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->stacksize=0;
    return Ok;
}

//���ջ��Ԫ��
Status GetTop(SqStack *s, SElemType *e)
{
    if(s->top == s->base) return Error;
    *e = *(s->top - 1);
    return Ok;
}

//ѹջ
Status Push(SqStack *s, SElemType e)
{
    if(s->top - s->base >= s->stacksize)//ջ��
    {
        s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!s->base)
        {
            puts("�洢�ռ����ʧ�ܣ�");
            return Error;
        }
        s->top = s->base + s->stacksize;//�޸�ջ��λ��
        s->stacksize += STACKINCREMENT;//�޸�ջ����

    }
    *s->top++  = e;
    return Ok;
}

//��ջ
Status Pop(SqStack *s, SElemType *e)
{
    if(s->top == s->base) return Error;
    /*˵�����˴�����ʹ���Ի�ʵ���ϴ�Ԫ�ز�û����ɾ����
    ����S.top�У������������Ԫ�أ��ͻᱻ����
    */
    --s->top;
    *e = *(s->top);
    return Ok;
}

Status visit(SElemType c)
 {
   printf("%d ",c);
   return Ok;
 }

Status StackTraverse(SqStack *s){
    if(s->base == NULL) return Error;
    if(s->top == s->base) puts("ջ��û��Ԫ��");
    SElemType *p = s->top;
    SElemType *q = s->base;
    printf("\n");
    while(p > q){
       visit(*q++);
    }
    printf("\n");
    return Ok;
}

//���Դ���
int main()
{
    SqStack a;
    SqStack *s = &a;
    SElemType e;
    InitStack(s);
    int n;
    puts("������Ҫ��ջ�ĸ�����");
    scanf("%d", &n);
    while(n--)
    {
        int m;
        scanf("%d", &m);
        Push(s, m);
    }
    StackTraverse(s);
    GetTop(s, &e);
    printf("ջ����Ԫ���ǣ�%d\n", e);
    puts("8��ջ��");
    Push(s, 8);
    StackTraverse(s);
    Pop(s, &e);
    printf("��ջ��Ԫ���ǣ�%d\n", e);
    //�жϳ�ջ��Ԫ���Ƿ񻹴������ڴ���
    printf("��ջ��Ԫ����: %d\n", *s->top);
    Destroy(s);
    return 0;
}
