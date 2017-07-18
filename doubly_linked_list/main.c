#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node pNode;
typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;
/* 初始化双向循环链表，head的头尾均指向本身 */
void InitList(pNode **head)
{
    *head = (pNode *)malloc(sizeof(pNode));
    if ((*head) == NULL)
        exit(0);
    (*head)->next = (*head);
    (*head)->prev = (*head);
}
/* 插入，在链表第n个位置插入元素 */
int InsertList(pNode **head)
{
    pNode *p, *s;
    int i = 0;
    p = (*head)->prev; //p始终指向尾节点
    int n;
    printf("The input to the position of the insert:");
    scanf("%d", &n);
    s = (pNode *)malloc(sizeof(pNode));
    if (s == NULL)
        exit(0);
    printf("Input to insert element value:");
    scanf("%d", &s->data);
    if (s->data <= 0)
        return 0;
    while(i < n) //n输入从1开始
    {
        i++;
        p = p->next;
    }
    s->prev = p;
    s->next = p->next;
    p->next->prev = s;
    p->next = s;
    InsertList(head);
}
/* 遍历打印 */
void PrintList(pNode *head)
{
    pNode *p;
    p = head->next;//从头结点之后开始循环打印
    while(p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/* 清空链表，保留头指针 */
void ClearList(pNode **head)
{
    pNode *p;
    p = (*head)->next;
    while(p != (*head))
    {
        p = p->next;
        free(p->prev);
    }
    (*head)->next = (*head)->prev = (*head);//头节点的两个指针域指向自身
}
/* 彻底销毁链表，头指针置空 */
void DestroyList(pNode **head)
{
    pNode *p;
    p = (*head)->next;
    while(p != (*head))
    {
        p = p->next;
        free(p->prev);
    }
    free(*head);
    (*head) = NULL;
}
int main(int argc, char const *argv[])
{
    pNode *head;
    InitList(&head);
    InsertList(&head);
    PrintList(head);
    ClearList(&head);
    printf("验证是否头节点指向自身:\n");
    printf("%p %p %p\n", head, head->next, head->prev); //验证是否头节点指向自身
    DestroyList(&head);
    printf("验证是否已经完全销毁:\n");
    printf("%p\n", head);//验证是否已经完全销毁
    return 0;
}
