
// 第五章 树与二叉树
// 5.3.3 二 8
// 给定二叉树,确定双分支结点个数.
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 思路 递归
// 如果 T=NULL return;
void swap(BitTree T) {
    if (T == NULL) return;
    BitNode *p = T->rchild;
    T->rchild = T->lchild;
    T->lchild = p;
    swap(T->lchild);
    swap(T->rchild);
}