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
    if (L->next == L) //��ָ����ָ��ͷ���ʱ֤��û��������㣬����Ϊ��
    {
        printf("The list is empty\n");
    }
}

void InitList_CL(struct LNode **L)
{
    *L = (struct LNode *)malloc(sizeof(struct LNode));
    if (!*L)
        exit(0);
    (*L)->next = (*L); //ָ����ָ��ͷ���
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
    while(i < n - 1) //��λ��1��ʼ����
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
    InitList_CL(&L); //��ʼ������
    ListEmpty_CL(L); //�ж������Ƿ�Ϊ��
    ListInsert_CL(&L); //�������е�n��λ�ò���Ԫ��
    ListPrint_CL(L); //��ӡ����
    return 0;
}
