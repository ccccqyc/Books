// 第五章 树与二叉树
// 5.3.3 二 6
// 已知先序A[],中序B[]求二叉树
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

BitTree PreInCreat(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2) {
    BitNode *root = (BitNode *)malloc(sizeof(BitNode));
    root->data = A[l1];
    int i = l2;
    for (; B[i] != root->data; i++)
        ;
    int llen = i - l2;
    int rlen = h2 - i;
    if (llen > 0)
        root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    else
        root->lchild = NULL;
    if (rlen > 0)
        root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    else
        root->rchild = NULL;

    return root;
}
