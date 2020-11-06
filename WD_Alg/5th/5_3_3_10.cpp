// 第五章 树与二叉树
// 5.3.3 二 10
// 求先序遍历第K个结点的值
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;
int count = 10;
void visit(BitNode p) {}
// 思路先序遍历,计数
ElemType function(BitTree T, int k) {
    BitNode *p = T;
    Stack S;
    InitStack(S);
    while (p || isEmpty(S)) {
        if (p) {
            push(S, p);
            p = p->lchild;
            k--;
            if (k == 0) return p->data;
        } else {
            pop(S, p);
            p = p->rchild;
        }
    }
}