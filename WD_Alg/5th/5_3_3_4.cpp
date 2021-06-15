// 第五章 树与二叉树
// 5.3.3 二 4
// 层序算法逆序
#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

void vist(BitNode *T);

void function(BitTree T) {
    BitNode *p = T;
    if (p == NULL) {
        return;
    }

    Stack S;
    initStack(S);
    Queue Q;
    initQueue(Q);
    Enqueue(Q, p);
    while (!isEmpty(Q)) {
        Dequeue(Q, p);
        push(S, p);
        if (p->lchild != NULL) Enqueue(Q, p->lchild);
        if (p->rchild != NULL) Enqueue(Q, p->rchild);
    }
    while (!isEmpty(S)) {
        pop(S, p);
        visit(p);
    }
}