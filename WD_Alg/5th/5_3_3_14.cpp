// 第五章 树与二叉树
// 5.3.3 二 14
// 非空二叉树宽度
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 思路:层序遍历,计数每一行
int Width(BitTree T) {
    BitNode *p = T;
    int width = 1;
    int currentwidth = 1;
    Queue Q;
    InitQueue(Q);  // 利用队列 层序遍历
    Enqueue(Q, p);
    while (!isEmpty(Q)) {
        Dequeue(Q,p);
        if(p->lchild){
            Enqueue(Q,p);
        }
        if(p->rchild){
            Enqueue(Q,p);
        }
        
    }

    return width;
}