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

//初始化栈
Status InitStack(SqStack *s)
{
    s->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
    if(!s->base)
    {
        puts("存储空间分配失败！");
        return Error;
    }
    s->top = s->base;
    s->stacksize = INIT_SIZE;
    return Ok;
}

//清空栈
Status ClearStack(SqStack *s)
 {
   s->top = s->base;
   return Ok;
 }

//栈是否为空
Status StackEmpty(SqStack *s)
 {
   if(s->top == s->base)
     return True;
   else
     return False;
 }

//销毁栈
Status Destroy(SqStack *s)
{
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->stacksize=0;
    return Ok;
}

//获得栈顶元素
Status GetTop(SqStack *s, SElemType *e)
{
    if(s->top == s->base) return Error;
    *e = *(s->top - 1);
    return Ok;
}

//压栈
Status Push(SqStack *s, SElemType e)
{
    if(s->top - s->base >= s->stacksize)//栈满
    {
        s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!s->base)
        {
            puts("存储空间分配失败！");
            return Error;
        }
        s->top = s->base + s->stacksize;//修改栈顶位置
        s->stacksize += STACKINCREMENT;//修改栈长度

    }
    *s->top++  = e;
    return Ok;
}

//弹栈
Status Pop(SqStack *s, SElemType *e)
{
    if(s->top == s->base) return Error;
    /*说明：此处容易使人迷惑，实际上此元素并没真正删除，
    仍在S.top中，但是如果插入元素，就会被更新
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
    if(s->top == s->base) puts("栈中没有元素");
    SElemType *p = s->top;
    SElemType *q = s->base;
    printf("\n");
    while(p > q){
       visit(*q++);
    }
    printf("\n");
    return Ok;
}

//测试代码
int main()
{
    SqStack a;
    SqStack *s = &a;
    SElemType e;
    InitStack(s);
    int n;
    puts("请输入要进栈的个数：");
    scanf("%d", &n);
    while(n--)
    {
        int m;
        scanf("%d", &m);
        Push(s, m);
    }
    StackTraverse(s);
    GetTop(s, &e);
    printf("栈顶的元素是：%d\n", e);
    puts("8进栈后：");
    Push(s, 8);
    StackTraverse(s);
    Pop(s, &e);
    printf("出栈的元素是：%d\n", e);
    //判断出栈后元素是否还存在于内存中
    printf("出栈的元素是: %d\n", *s->top);
    Destroy(s);
    return 0;
}
