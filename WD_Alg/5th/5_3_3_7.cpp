// 第五章 树与二叉树
// 5.3.3 二 7
// 判定二叉树是否是是完全二叉树
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 思路
// 以层序入队,遇到空结点查看它之后是否有非空结点,
// 若有则是非完全二叉树

bool function(BitTree T) {
    BitNode *p = T;
    if (p == NULL) return true;
    Queue Q;
    InitQueue(Q);
    EnQueue(p);            // 根节点入队
    while (!isEmpty(Q)) {  // 只要队列非空
        DeQueue(Q, p);     //出队

        if (p == NULL) {
            // 队列中剩下全是空结点 则是完全二叉树
            // 队列中剩余含非空结点 则是非完全二叉树
            BitNode *temp;
            while (!isEmpty(Q)) {
                DeQueue(Q, temp);
                if (temp != NULL) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        EnQueue(Q, p->lchild);
        EnQueue(Q, p->rchild);
    }
}