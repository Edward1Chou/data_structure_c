//单链表存储结构
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

//获取链表的长度
Status getListLength(LinkList L){
    int i = 0; //计数器
    while(L->next){
        L = L->next;
        i++;
    }
    return i;
}

/*
单链表的读取,用e返回L中的第i个元素的值 , 0 < i < L.length
L是带头结点的单链表的头指针
*/
Status getElem(LinkList L, int i, ElemType *e){
    int j = 1; //计数器
    LinkList p;
    p = L->next;    //p为第一个节点
    while(p && j < i){ //p不为null
        p = p->next;
        j++;
    }
    if(!p || i < j){
        return ERROR;   //查找的元素不存在
    }
    *e = p->data;   //去第i个元素的数据
    return OK;
}


void CreateList(LinkList *L, int n) {
// 逆序输入n个元素的值，建立带表头结点的单链线性表L
    int i;
    LinkList p;
    (*L) = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; //先建立一个带头结点的单链表
    for (i = n; i > 0; --i){
        p = (LinkList)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = (*L)->next; (*L)->next = p;
    }
}

//遍历单链表,输出值
void listTraverse(LinkList L){
    if(L->next == NULL){
        printf("链表为空");
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

//链表的插入 将e插入到第i个位置之前 0 < i < listLenght + 1
//定位到第i个节点,生成一个新的节点,数据e保存在新的节点中,最后插入到链表中
Status listInsert(LinkList *L, int i, ElemType e) {
    int j = 1;
    LinkList p, s;
    p = *L;
    while(p && j < i){ //p不为null
        p = p->next;
        j++;
    }
    if(!p || i < j){    //查找失败
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node)); //生成一个新的节点
    s->data = e;
    s->next = p->next;  //插入新节点
    p->next = s;
    return OK;
}

//链表删除 从链表中删除第i个元素,将删除的元素保存到e中
Status ListDelete(LinkList *L, int i, ElemType *e){
    int j = 1;
    LinkList p, q;
    p = *L;
    while(p && i > j){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return ERROR;   //查找失败
    }
    q = p->next;
    *e = q->data;   //保存要删除的数据
    p->next = q->next;  //将q的后继赋值给p的后继
    free(q);    //释放空间
    return OK;
}

//删除所有的节点
Status clearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while(p){       //循环删除每一个节点
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;  //头结点
    return OK;
}

int main(void){
    LinkList L;
    CreateList(&L, 10);
    printf("初始化10个元素,分别是: \n");
    listTraverse(L);
    ElemType e;
    getElem(L, 4, &e);
    printf("链表中第4个元素是: %d \n",e);
    printf("链表的长度是: %d \n",getListLength(L));
    listInsert(&L, 4, 12);
    printf("在链表第4个元素之前插入12 \n");
    listTraverse(L);
    ListDelete(&L, 5, &e);
    printf("在链表中删除第5个元素 \n");
    listTraverse(L);
    clearList(&L);
    printf("清除链表之后的元素: \n");
    listTraverse(L);
    return OK;
}






