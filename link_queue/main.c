#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int QElemType;
typedef struct Node
{
    QElemType data;
    struct Node *next;
} QNode;
/* ����ʽ���е�ͷβ�ڵ�ָ�붨���Ϊһ�������Ľṹ��,�����������ڵ�ʱռ�ù���Ŀռ� */
typedef struct
{
    QNode *front;
    QNode *rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
    if (!Q->front)
        exit(OVERFLOW);
    Q->rear->next = NULL; //rear.nextʼ��ָ��NULL,ͷ���front����
    return OK;
}

Status InQueue(LinkQueue *Q, int elem)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = elem;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status PrintQueue(LinkQueue Q)
{
    QNode *p;
    p = Q.front->next;
    printf("the queue is:");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status OutQueue(LinkQueue *Q, QElemType *e)
{
    QNode *p;
    if(Q->front == Q->rear) return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) Q->rear = Q->front;
    free(p);
    return OK;
}

Status EmptyQueue(LinkQueue Q)
{
    if (Q.front->next == NULL)
        printf("\nThe queue is empty!\n");
    else printf("\nThe queue is not empty!\n");
    return OK;
}

Status DestroyQueue(LinkQueue *Q){
    //��������
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

//���Դ���
int main()
{
    LinkQueue queue;
    InitQueue(&queue);
    int elem, e;
    printf("input:");
    while(scanf("%d", &elem) != EOF) //ctrl+z
    {
        InQueue(&queue, elem);
    }
    PrintQueue(queue);
    printf("After deQueue:\n");
    OutQueue(&queue, &e);
    PrintQueue(queue);
    printf("ɾ����Ԫ���ǣ�%d\n", e);
    EmptyQueue(queue);
    DestroyQueue(&queue);
    return OK;
}
