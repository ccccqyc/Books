// 第五章 树与二叉树
// 5.3.3 二 17
// 判断两科二叉树是否相似
#include <malloc.h>

#include <cstdio>
#define MaxSize 50

typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

//递归 如果两个子树均为NULL返回true
// 如果 子树根节点值不同则返回false
bool function(BitTree T1, BitTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return true;
    }
    if (T1->data != T2->data) {
        return false;
    }
    return function(T1->lchild, T2->lchild) && function(T1->rchild, T2->rchild);
}