#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 哈夫曼树的结构体 */
typedef struct stHuNode
{
    int data; //权值
    struct stHuNode* lchild, *rchild;
}HUNODE;


/*
* 找出权值数组里面,最小的两个权值下标
* 函数请参：HUNODE *pArray[] 存放节点的指针数组
            int n 数组里面的元素个数
            int* p1 存放最小权值的下标
            int* p2 存放第二小权值的下标
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
        /* 当前的下标下面是有节点的*/
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
* 函数功能：构建哈夫曼树
* 函数请参：int* a 权值数组
            int n 这个数组里面有多少个数据
*/

HUNODE* createHuTree(int* a, int n)
{
    int index = 0;

    int fir_small = 0, sec_small = 0;

    /* 定义一个指针数组,最大是100 */
    HUNODE *pArray[100];
    HUNODE *pNewNode = NULL;


    /* 先创建n个root节点*/
    memset(pArray,0,sizeof(HUNODE)*n);
    for(index = 0; index < n; index++)
    {
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data = a[index];
        pNewNode->lchild = NULL;
        pNewNode->rchild = NULL;

        /* 把这个节点存放在指针数组中去 */
        pArray[index] = pNewNode;
    }

    /* 构建哈夫曼树 */
    for(index = 0; index < n-1; index++)
    {
        /* fir_small 存放最小权值的下标  sec_small存放第二个小的权值下标*/
        findSmallData(pArray,n,&fir_small,&sec_small);

        /* 分配节点内存 */
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data = pArray[fir_small]->data + pArray[sec_small]->data;

        /* 最小的是左孩子，第二小的是右孩子 */
        pNewNode->lchild = pArray[fir_small];
        pNewNode->rchild = pArray[sec_small];

        /* 把新的节点放入到指针数组里面去 */
        pArray[fir_small] = NULL;
        pArray[sec_small] = pNewNode;

    }
    return pNewNode;
}

/* 前序遍历该二叉树 */
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

    /* 构建哈夫曼树
       18 7 11 5 6 2 4
    */
    root = createHuTree(a,4);

    /* 前序遍历 */
    preOrderHuffMan(root);
    printf("\n");

    return 0;
}
