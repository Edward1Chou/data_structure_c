/*线性表功能的实现*/
#include<stdio.h>

//定义常量 存储空间的初始化分配
#define MAXSIZE 20
#define TRUE 1
#define ERROR -1
#define FALSE 0
#define OK 1

//用typedef定义类型
typedef int Status;
typedef int ElemType;
//定义一个结构体类型
typedef struct{
    ElemType data[MAXSIZE];
    int length;
} SqList;

//初始化函数
Status initList(SqList *L){
    L->length = 0;
    return OK;
}

//返回线性表的长度
Status getListLength(SqList L){
    return L.length;
}

//线性表为空返回true,否则返回false
Status listEmpty(SqList L){
    if(L.length == 0){
        return TRUE;
    }
    return FALSE;
}

//线性表清空,长度为0
Status clearList(SqList *L){
    L->length = 0;
    return OK;
}
//获取指定的元素的值,返回下标为i - 1的元素,赋值给e
Status getElem(SqList L, int i, ElemType *e){
    //判断元素位置是否合法[i]
    if(i > L.length || i < 1){
        printf("查找的位置不正确 \n");
        return ERROR;
    }
    //判断线性表是否为空
    if(listEmpty(L)){
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

//在线性表中查找指定的e相等的元素,如果查找成功,返回该元素的下标,否则返回ERROR
Status locateElem(SqList L, ElemType e){
    int i;
    for(i = 0; i < L.length; i++){
        if(L.data[i] == e){
            return i + 1;
        }
    }
    printf("没有查找到元素 %d 指定的下标\n",e);
    return ERROR;
}

//自动创建 MAXSIZE 个元素,并赋值为0
Status createList(SqList *L){
    int i;
    for(i = 0; i < 10; i++){
        L->data[i] = i*i;
    }
    L->length = 10;
    return OK;
}

//在线性表中第i个位置前插入新元素e
Status listInsert(SqList *L, int i, ElemType e){
    //判断长度是否可以允许插入新的数据
    if(L->length >= MAXSIZE){
        printf("空间已满,不能再插入数据\n");
        return FALSE;
    }
    //判断插入位置的合法性
    if(i < 1 || i > L->length + 1) {
        printf("插入位置不正确\n");
        return FALSE;
    }
    int j;
    if(i == L->length + 1){
        L->data[i - 1] = e;
    }else{
        for(j = L->length; j >= i; j--){
            L->data[j] = L->data[j - 1];
        }
        L->data[i - 1] = e;
    }
    L->length++;
    return TRUE;
}

//删除线性表中第i个元素,成功后表长减1,用e返回其值
Status deleteList(SqList *L, int i, ElemType *e){
    //判断线性表是否为空
    if(listEmpty(*L)){
        return ERROR;
    }
    //判断删除的位置是否合法
    if(i < 1 || i > L->length) {
        printf("删除位置不合法\n");
        return ERROR;
    }
    *e = L->data[i - 1];
    for(i; i < L->length; i++){
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return TRUE;
}

//遍历线性表
Status listTraverse(SqList L){
    int i;
    for(i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    return OK;
}

//主程序
int main(void){
    SqList L;
    ElemType e;
    initList(&L);
    int option = 1;
    int input_number;
    int res;
    int flag; // 判断是否出错
    ElemType input_value;
    printf("\n1.遍历线性表 \n2.创建线性表 \n3.清空线性表 \n4.线性表插入 \n5.查找表中元素 \n6.判断元素是否在表中 \n7.删除某个元素 \n8.线性表长度\n9.线性表是否为空\n0.退出 \n请选择你的操作：\n");
    while(option){
        scanf("%d",&option);
        switch(option){
            case 0:
                return OK;
                break;
            case 1:
                listTraverse(L);
                break;
            case 2:
                createList(&L);
                listTraverse(L);
                break;
            case 3:
                clearList(&L);
                //listTraverse(L);
                break;
            case 4:
                printf("请输入插入的位置:");
                scanf("%d",&input_number);
                printf("\n");
                printf("请输入插入的值:");
                scanf("%d",&input_value);
                printf("\n");
                listInsert(&L, input_number, input_value);
                listTraverse(L);
                break;
            case 5:
                printf("请输入要查找的位置:");
                scanf("%d",&input_number);
                printf("\n");
                flag = getElem(L, input_number, &input_value);
                if(flag == 1) printf("第%d个元素的值为:%d\n",input_number,input_value);
                break;
            case 6:
                printf("请输入要查找的元素:");
                scanf("%d",&input_value);
                printf("\n");
                res = locateElem(L, input_value);
                if(res != ERROR){
                    printf("值为%d在表中的第%d个位置\n",input_value, res);
                }
                break;
            case 7:
                printf("要删除第几个元素？");
                scanf("%d",&input_number);
                printf("\n");
                deleteList(&L, input_number, &input_value);
                listTraverse(L);
                break;
            case 8:
                res = getListLength(L);
                printf("线性表的长度是:%d\n",res);
                break;
            case 9:
                res = listEmpty(L);
                if(res){
                    printf("线性表的是空的\n");
                }else{
                    printf("线性表的是不是空的\n");
                }
                break;
        }
    }
    return OK;
}
