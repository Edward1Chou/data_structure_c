/*
    ������(binary tree) - ��ʽ�洢�ṹ
    ʵ�� �������Ĵ����ͱ���
    �����ʹ�����Ϊ���� ǰ��,����,����
    ���� ���ݲο� <AB D  C  > �ո���Ҫ���� ��
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0;

typedef int Status;
typedef char TElemType;

//��㶨��
typedef struct BiTNode {
    TElemType data;     //������
    struct BiTNode *lchild, *rchild;    //���Һ���ָ��
}BiTNode, *BiTree;

//ǰ�����(previous order traverse)
void preOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    }
    printf("%c ", T->data);         //��һ�� ��ʾ�������
    preOrderTraverse(T->lchild);    //�ڶ��� ǰ�����������
    preOrderTraverse(T->rchild);        //������ ǰ�����������
}

//�������(intermediate order traverse)
void inOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    }
    inOrderTraverse(T->lchild); //��һ�� �������������
    printf("%c ", T->data);     //�ڶ��� ��ʾ�������
    inOrderTraverse(T->rchild); //������ �������������
}

//�������(post order traverse)
void postOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

//�������Ľ���  ��ǰ������������н���ֵ (һ���ַ�)
//' '��ʾ���� ��ÿ�����ȷ���Ƿ������Һ���,������������ʾ������
//�������˳���������� , �����66 67 68��˳��Ҫ��һ�� ,���Բ��ձ����Ĵ�������Ͳ�ʵ����.
//ʵ�����룺A B C �� �� D E �� G �� �� F �� �� ��
void createBiTree(BiTree *T){
    TElemType ch[2];
    scanf("%s",&ch[0]);
    if(strcmp(ch,"@")==0){
        *T = NULL;
    }
    else{
        *T = (BiTree)malloc(sizeof(BiTNode));   //���ɽ��
        if(!(*T)){  //����ʧ��
            printf("�������ʧ��\n");
            exit(-2);//OVERFLOW
        }
        (*T)->data = ch[0]; //����㸳ֵ
        createBiTree(&(*T)->lchild); //����������
        createBiTree(&(*T)->rchild);    //����������
    }
}

int main(void){
    BiTree T;
    int option = 1;
    printf("\n 1.ǰ�򴴽�������\n 2.ǰ�����������\n 3.�������������\n 4.�������������\n 0.�˳�\n");
    while(option){
        scanf("%d", &option);
        fflush(stdin);  //ˢ�»����� ����Ǳ���� ��Ȼ������ʱ���������ݻ������ɻ�
        switch(option){
            case 1:
                createBiTree(&T);
                printf("�����������ɹ�\n");
                break;
            case 2:
                printf("ǰ�������\n");
                preOrderTraverse(T);
                printf("\n");
                break;
            case 3:
                printf("���������\n");
                inOrderTraverse(T);
                printf("\n");
                break;
            case 4:
                printf("���������\n");
                postOrderTraverse(T);
                printf("\n");
                break;
            case 0:
                return OK;
                break;
        }
    }
    return OK;
}
