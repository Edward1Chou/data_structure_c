/*
    二叉树(binary tree) - 链式存储结构
    实现 二叉树的创建和遍历
    遍历和创建分为三种 前序,中序,后序
    输入 数据参考 <AB D  C  > 空格是要输入 的
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0;

typedef int Status;
typedef char TElemType;

//结点定义
typedef struct BiTNode {
    TElemType data;     //数据域
    struct BiTNode *lchild, *rchild;    //左右孩子指针
}BiTNode, *BiTree;

//前序遍历(previous order traverse)
void preOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    }
    printf("%c ", T->data);         //第一步 显示结点数据
    preOrderTraverse(T->lchild);    //第二步 前序遍历左子树
    preOrderTraverse(T->rchild);        //第三步 前序遍历右子树
}

//中序遍历(intermediate order traverse)
void inOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    }
    inOrderTraverse(T->lchild); //第一步 中序遍历左子树
    printf("%c ", T->data);     //第二步 显示结点数据
    inOrderTraverse(T->rchild); //第三步 中序遍历右子树
}

//后序遍历(post order traverse)
void postOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

//二叉树的建立  按前序输入二叉树中结点的值 (一个字符)
//' '表示空树 让每个结点确定是否有左右孩子,构造二叉链表表示二叉树
//如果输入顺序按中序或后序 , 代码的66 67 68行顺序要换一下 ,可以参照遍历的代码这里就不实现了.
//实例输入：A B C 空 空 D E 空 G 空 空 F 空 空 空
void createBiTree(BiTree *T){
    TElemType ch[2];
    scanf("%s",&ch[0]);
    if(strcmp(ch,"@")==0){
        *T = NULL;
    }
    else{
        *T = (BiTree)malloc(sizeof(BiTNode));   //生成结点
        if(!(*T)){  //创建失败
            printf("结点申请失败\n");
            exit(-2);//OVERFLOW
        }
        (*T)->data = ch[0]; //给结点赋值
        createBiTree(&(*T)->lchild); //构造左子树
        createBiTree(&(*T)->rchild);    //构造右子树
    }
}

int main(void){
    BiTree T;
    int option = 1;
    printf("\n 1.前序创建二叉树\n 2.前序遍历二叉树\n 3.中序遍历二叉树\n 4.后序遍历二叉树\n 0.退出\n");
    while(option){
        scanf("%d", &option);
        fflush(stdin);  //刷新缓冲区 这个是必须的 不然创建的时候输入数据会让你疑惑
        switch(option){
            case 1:
                createBiTree(&T);
                printf("二叉树创建成功\n");
                break;
            case 2:
                printf("前序遍历：\n");
                preOrderTraverse(T);
                printf("\n");
                break;
            case 3:
                printf("中序遍历：\n");
                inOrderTraverse(T);
                printf("\n");
                break;
            case 4:
                printf("后序遍历：\n");
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
