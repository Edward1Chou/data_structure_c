/*���Ա��ܵ�ʵ��*/
#include<stdio.h>

//���峣�� �洢�ռ�ĳ�ʼ������
#define MAXSIZE 20
#define TRUE 1
#define ERROR -1
#define FALSE 0
#define OK 1

//��typedef��������
typedef int Status;
typedef int ElemType;
//����һ���ṹ������
typedef struct{
    ElemType data[MAXSIZE];
    int length;
} SqList;

//��ʼ������
Status initList(SqList *L){
    L->length = 0;
    return OK;
}

//�������Ա�ĳ���
Status getListLength(SqList L){
    return L.length;
}

//���Ա�Ϊ�շ���true,���򷵻�false
Status listEmpty(SqList L){
    if(L.length == 0){
        return TRUE;
    }
    return FALSE;
}

//���Ա����,����Ϊ0
Status clearList(SqList *L){
    L->length = 0;
    return OK;
}
//��ȡָ����Ԫ�ص�ֵ,�����±�Ϊi - 1��Ԫ��,��ֵ��e
Status getElem(SqList L, int i, ElemType *e){
    //�ж�Ԫ��λ���Ƿ�Ϸ�[i]
    if(i > L.length || i < 1){
        printf("���ҵ�λ�ò���ȷ \n");
        return ERROR;
    }
    //�ж����Ա��Ƿ�Ϊ��
    if(listEmpty(L)){
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

//�����Ա��в���ָ����e��ȵ�Ԫ��,������ҳɹ�,���ظ�Ԫ�ص��±�,���򷵻�ERROR
Status locateElem(SqList L, ElemType e){
    int i;
    for(i = 0; i < L.length; i++){
        if(L.data[i] == e){
            return i + 1;
        }
    }
    printf("û�в��ҵ�Ԫ�� %d ָ�����±�\n",e);
    return ERROR;
}

//�Զ����� MAXSIZE ��Ԫ��,����ֵΪ0
Status createList(SqList *L){
    int i;
    for(i = 0; i < 10; i++){
        L->data[i] = i*i;
    }
    L->length = 10;
    return OK;
}

//�����Ա��е�i��λ��ǰ������Ԫ��e
Status listInsert(SqList *L, int i, ElemType e){
    //�жϳ����Ƿ������������µ�����
    if(L->length >= MAXSIZE){
        printf("�ռ�����,�����ٲ�������\n");
        return FALSE;
    }
    //�жϲ���λ�õĺϷ���
    if(i < 1 || i > L->length + 1) {
        printf("����λ�ò���ȷ\n");
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

//ɾ�����Ա��е�i��Ԫ��,�ɹ������1,��e������ֵ
Status deleteList(SqList *L, int i, ElemType *e){
    //�ж����Ա��Ƿ�Ϊ��
    if(listEmpty(*L)){
        return ERROR;
    }
    //�ж�ɾ����λ���Ƿ�Ϸ�
    if(i < 1 || i > L->length) {
        printf("ɾ��λ�ò��Ϸ�\n");
        return ERROR;
    }
    *e = L->data[i - 1];
    for(i; i < L->length; i++){
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return TRUE;
}

//�������Ա�
Status listTraverse(SqList L){
    int i;
    for(i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    return OK;
}

//������
int main(void){
    SqList L;
    ElemType e;
    initList(&L);
    int option = 1;
    int input_number;
    int res;
    int flag; // �ж��Ƿ����
    ElemType input_value;
    printf("\n1.�������Ա� \n2.�������Ա� \n3.������Ա� \n4.���Ա���� \n5.���ұ���Ԫ�� \n6.�ж�Ԫ���Ƿ��ڱ��� \n7.ɾ��ĳ��Ԫ�� \n8.���Ա���\n9.���Ա��Ƿ�Ϊ��\n0.�˳� \n��ѡ����Ĳ�����\n");
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
                printf("����������λ��:");
                scanf("%d",&input_number);
                printf("\n");
                printf("����������ֵ:");
                scanf("%d",&input_value);
                printf("\n");
                listInsert(&L, input_number, input_value);
                listTraverse(L);
                break;
            case 5:
                printf("������Ҫ���ҵ�λ��:");
                scanf("%d",&input_number);
                printf("\n");
                flag = getElem(L, input_number, &input_value);
                if(flag == 1) printf("��%d��Ԫ�ص�ֵΪ:%d\n",input_number,input_value);
                break;
            case 6:
                printf("������Ҫ���ҵ�Ԫ��:");
                scanf("%d",&input_value);
                printf("\n");
                res = locateElem(L, input_value);
                if(res != ERROR){
                    printf("ֵΪ%d�ڱ��еĵ�%d��λ��\n",input_value, res);
                }
                break;
            case 7:
                printf("Ҫɾ���ڼ���Ԫ�أ�");
                scanf("%d",&input_number);
                printf("\n");
                deleteList(&L, input_number, &input_value);
                listTraverse(L);
                break;
            case 8:
                res = getListLength(L);
                printf("���Ա�ĳ�����:%d\n",res);
                break;
            case 9:
                res = listEmpty(L);
                if(res){
                    printf("���Ա���ǿյ�\n");
                }else{
                    printf("���Ա���ǲ��ǿյ�\n");
                }
                break;
        }
    }
    return OK;
}
