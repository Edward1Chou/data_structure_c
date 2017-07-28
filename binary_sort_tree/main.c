#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *lchild, *rchild;
}BSTNode, *BSTree;

//插入
int InsertBST(BSTree *bst, int k)
{
    BSTree r, s, pre;
    r = (BSTree)malloc(sizeof(BSTNode));
    r->key = k;
    r->lchild = NULL;
    r->rchild = NULL;
    if(*bst == NULL)
    {
        *bst = r;
        return 1;
    }
    pre = NULL;
    s = *bst;
    while(s)
    {
        if(k == s->key)
            return 0;
        else if(k < s->key)
        {
            pre = s;
            s = s->lchild;
        }
        else
        {
            pre = s;
            s = s->rchild;
        }
    }
    if(k < pre->key)
        pre->lchild = r;
    else
        pre->rchild = r;
    return 1;
}


void CreateBST(BSTree *bst)
{
    int key;
    *bst = NULL;
    scanf("%d", &key);
    while(key != -1)
    {
        InsertBST(bst, key);
        scanf("%d", &key);
    }
}

/*
 *打印二叉树：
 *中序遍历
 * */
void InOrder(BSTree root)
{
    if(root != NULL)
    {
        InOrder(root->lchild);
        printf("%d ", root->key);
        InOrder(root->rchild);
    }
}

/*
 *搜索
 * */
BSTree SearchBST(BSTree bst, int key)
{
    BSTree q;
    q = bst;
    //递归
    while(q)
    {
        if(q->key == key)
            return q;
        if(q->key > key)
            q=q->lchild;
        else
            q=q->rchild;
    }
    return NULL;                        //查找失败
}

int main()
{
    BSTree T;
    int tag = 1;
    int m, n;
    printf("建立二叉排序树，请输入序列以-1结束: ");
    CreateBST(&T);
    printf("中序遍历二叉树，序列为：");
    InOrder(T);
    printf("\n");
    while(tag != 0)
    {
        printf("请输入你要查找的元素:");
        scanf("%d", &n);
        if(SearchBST(T, n) == NULL)
            printf("抱歉查找失败!");
        else
            printf("查找成功！查找的数字为%d", SearchBST(T,n)->key);
        printf("是否继续查找 是 ：请按 1 否则按 0:");
        scanf("%d", &tag);
    }
    return 0;
}
