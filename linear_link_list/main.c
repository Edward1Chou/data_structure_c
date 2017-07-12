//������洢�ṹ
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;

    struct Node *next;
}Node, *LinkList;

//��ȡ����ĳ���
Status getListLength(LinkList L){
    int i = 0; //������
    while(L->next){
        L = L->next;
        i++;
    }
    return i;
}

/*
������Ķ�ȡ,��e����L�еĵ�i��Ԫ�ص�ֵ , 0 < i < L.length
L�Ǵ�ͷ���ĵ������ͷָ��
*/
Status getElem(LinkList L, int i, ElemType *e){
    int j = 1; //������
    LinkList p;
    p = L->next;    //pΪ��һ���ڵ�
    while(p && j < i){ //p��Ϊnull
        p = p->next;
        j++;
    }
    if(!p || i < j){
        return ERROR;   //���ҵ�Ԫ�ز�����
    }
    *e = p->data;   //ȥ��i��Ԫ�ص�����
    return OK;
}


void CreateList(LinkList *L, int n) {
// ��������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
    int i;
    LinkList p;
    (*L) = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
    for (i = n; i > 0; --i){
        p = (LinkList)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = (*L)->next; (*L)->next = p;
    }
}

//����������,���ֵ
void listTraverse(LinkList L){
    if(L->next == NULL){
        printf("����Ϊ��");
    }else{
        LinkList p;
        p = L->next;
        while(p != NULL){
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

//����Ĳ��� ��e���뵽��i��λ��֮ǰ 0 < i < listLenght + 1
//��λ����i���ڵ�,����һ���µĽڵ�,����e�������µĽڵ���,�����뵽������
Status listInsert(LinkList *L, int i, ElemType e) {
    int j = 1;
    LinkList p, s;
    p = *L;
    while(p && j < i){ //p��Ϊnull
        p = p->next;
        j++;
    }
    if(!p || i < j){    //����ʧ��
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node)); //����һ���µĽڵ�
    s->data = e;
    s->next = p->next;  //�����½ڵ�
    p->next = s;
    return OK;
}

//����ɾ�� ��������ɾ����i��Ԫ��,��ɾ����Ԫ�ر��浽e��
Status ListDelete(LinkList *L, int i, ElemType *e){
    int j = 1;
    LinkList p, q;
    p = *L;
    while(p && i > j){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return ERROR;   //����ʧ��
    }
    q = p->next;
    *e = q->data;   //����Ҫɾ��������
    p->next = q->next;  //��q�ĺ�̸�ֵ��p�ĺ��
    free(q);    //�ͷſռ�
    return OK;
}

//ɾ�����еĽڵ�
Status clearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while(p){       //ѭ��ɾ��ÿһ���ڵ�
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;  //ͷ���
    return OK;
}

int main(void){
    LinkList L;
    CreateList(&L, 10);
    printf("��ʼ��10��Ԫ��,�ֱ���: \n");
    listTraverse(L);
    ElemType e;
    getElem(L, 4, &e);
    printf("�����е�4��Ԫ����: %d \n",e);
    printf("����ĳ�����: %d \n",getListLength(L));
    listInsert(&L, 4, 12);
    printf("�������4��Ԫ��֮ǰ����12 \n");
    listTraverse(L);
    ListDelete(&L, 5, &e);
    printf("��������ɾ����5��Ԫ�� \n");
    listTraverse(L);
    clearList(&L);
    printf("�������֮���Ԫ��: \n");
    listTraverse(L);
    return OK;
}






