// 第五章 树与二叉树
// 5.3.3 二 11
// 删除以值为X为根的子树 释放空间
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 思路 后序遍历 释放结点值为x的左结点和右结点 然后释放该结点
void deleteNode(BitTree &T) {
    if (T) {
        deleteNode(T->lchild);
        deleteNode(T->rchild);
        free(T);
    }
}

void PostOrder(BitTree &T, ElemType x) {
    Queue Q;
    InitQueue(Q); 
    BitNode *p = T;
    if (T) {
        // 根节点值x 直接删除释放
        if (T->data = x) {
            deleteNode(T);
            exit(0);
        }
        EnQueue(Q, T); //入队
        while (!isEmpty(Q)) {
            DeQueue(Q, p);
            if (p->lchild) {
                if (p->lchild->data == x) {
                    deleteNode(p->lchild);
                    p->lchild = NULL;
                } else {
                    EnQueue(Q, p->lchild);
                }
            }
            if (p->rchild) {
                if (p->rchild->data == x) {
                    deleteNode(p->rchild);
                    p->rchild = NULL;
                } else {
                    EnQueue(Q, p->rchild);
                }
            }
        }
    }
}