// 第五章 树与二叉树
// 5.3.3 二 3
// 后序遍历非递归算法.
#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

void vist(BitNode *T);

// 后续遍历递归算法
void postOrder(BitTree T) {
    BitTree p = T;
    while (p != NULL) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        vist(p);
    }
    return;
}

// 后续遍历非递归算法
void postOrder_2(BitTree T) {
    BitTree p = T, r = NULL;
    Stack S;
    InitStack(S);
    while(p!=NULL&&!isEmpty(S){
        if (p) {
            push(S, p);
            p = p->lchild;
        } else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
                push(S, p);
                p = p->lchild;
            } else {
                pop(S, p);
                vist(p);
                r = p;
                p = NULL;
            }
        }
    }
}