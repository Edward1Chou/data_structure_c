#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElemType;
typedef int Status;
struct LNode
{
    ElemType data;
    struct LNode *next;
};

void ListEmpty_CL(struct LNode *L)
{
    if (L->next == L) //当指针域指向头结点时证明没有其他结点，链表为空
    {
        printf("The list is empty\n");
    }
}

void InitList_CL(struct LNode **L)
{
    *L = (struct LNode *)malloc(sizeof(struct LNode));
    if (!*L)
        exit(0);
    (*L)->next = (*L); //指针域指向头结点
}

Status ListInsert_CL(struct LNode **L)
{
    int n, number, i = 0;
    printf("The input position n:");
    scanf("%d", &n);
    printf("The input digital number:");
    scanf("%d", &number);
    if (number < 1)
    {
        return 0;
    }
    struct LNode *p, *s;
    p = (*L)->next;
    while(i < n - 1) //从位置1开始输入
    {
        p = p->next;
        i++;
    }
    s = (struct LNode *)malloc(sizeof(struct LNode));
    s->data = number;
    s->next = p->next;
    p->next = s;
    if(p == *L)
    {
        *L = s;
    }
    ListInsert_CL(L);
}

void ListPrint_CL(struct LNode *L)
{
    struct LNode *p;
    p = L->next;
    while(p != L)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    struct LNode *L;
    InitList_CL(&L); //初始化链表
    ListEmpty_CL(L); //判断链表是否为空
    ListInsert_CL(&L); //在链表中第n个位置插入元素
    ListPrint_CL(L); //打印链表
    return 0;
}
