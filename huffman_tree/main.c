#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ���������Ľṹ�� */
typedef struct stHuNode
{
    int data; //Ȩֵ
    struct stHuNode* lchild, *rchild;
}HUNODE;


/*
* �ҳ�Ȩֵ��������,��С������Ȩֵ�±�
* ������Σ�HUNODE *pArray[] ��Žڵ��ָ������
            int n ���������Ԫ�ظ���
            int* p1 �����СȨֵ���±�
            int* p2 ��ŵڶ�СȨֵ���±�
*/
int findSmallData(HUNODE *pArray[] ,int n,int* p1, int* p2)
{
    int index = 0;
    int fir_small = 0xffff, sec_small = 0xffff;

    if(pArray == NULL)
    {
        return 1;
    }

    for(index = 0; index < n; index++)
    {
        /* ��ǰ���±��������нڵ��*/
        if(pArray[index] != NULL)
        {
            if(pArray[index]->data < fir_small)
            {
                sec_small = fir_small;
                fir_small = pArray[index]->data;

                *p2 = *p1;
                *p1 = index;
            }
            else if(pArray[index]->data < sec_small)
            {
                sec_small = pArray[index]->data;
                *p2 = index;
            }
        }
    }

    return 0;
}
/*
* �������ܣ�������������
* ������Σ�int* a Ȩֵ����
            int n ������������ж��ٸ�����
*/

HUNODE* createHuTree(int* a, int n)
{
    int index = 0;

    int fir_small = 0, sec_small = 0;

    /* ����һ��ָ������,�����100 */
    HUNODE *pArray[100];
    HUNODE *pNewNode = NULL;


    /* �ȴ���n��root�ڵ�*/
    memset(pArray,0,sizeof(HUNODE)*n);
    for(index = 0; index < n; index++)
    {
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data = a[index];
        pNewNode->lchild = NULL;
        pNewNode->rchild = NULL;

        /* ������ڵ�����ָ��������ȥ */
        pArray[index] = pNewNode;
    }

    /* ������������ */
    for(index = 0; index < n-1; index++)
    {
        /* fir_small �����СȨֵ���±�  sec_small��ŵڶ���С��Ȩֵ�±�*/
        findSmallData(pArray,n,&fir_small,&sec_small);

        /* ����ڵ��ڴ� */
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data = pArray[fir_small]->data + pArray[sec_small]->data;

        /* ��С�������ӣ��ڶ�С�����Һ��� */
        pNewNode->lchild = pArray[fir_small];
        pNewNode->rchild = pArray[sec_small];

        /* ���µĽڵ���뵽ָ����������ȥ */
        pArray[fir_small] = NULL;
        pArray[sec_small] = pNewNode;

    }
    return pNewNode;
}

/* ǰ������ö����� */
void preOrderHuffMan(HUNODE* root)
{
    if(root)
    {
        printf("%d  ",root->data);
        preOrderHuffMan(root->lchild);
        preOrderHuffMan(root->rchild);
    }
}

int main()
{
    int a[4] = {7,5,2,4};
    HUNODE* root = NULL;

    /* ������������
       18 7 11 5 6 2 4
    */
    root = createHuTree(a,4);

    /* ǰ����� */
    preOrderHuffMan(root);
    printf("\n");

    return 0;
}
