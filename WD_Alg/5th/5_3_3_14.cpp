// 第五章 树与二叉树
// 5.3.3 二 14
// 非空二叉树宽度
#include <malloc.h>

#include <cstdio>
#define MaxSize 50

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
        Dequeue(Q, p);
        if (p->lchild) {
            Enqueue(Q, p);
        }
        if (p->rchild) {
            Enqueue(Q, p);
        }
    }

    return width;
}

typedef struct {
    BitTree data[MaxSize];
    int level[MaxSize];
    int front, rear;
} QU;
// 层次遍历 所有结点层次
// 将所有结点和对应的层次放在同一个队列
// 通过扫描得出各层结点总数
// 最大总数就是宽度
int BitWidth(BitTree b) {
    QU Qu;
    BitTree p;
    int k, max, i, n;
    Qu.front = Qu.rear = -1;  //队空
    Qu.rear++;
    Qu.data[Qu.rear] = b;
    Qu.level[Qu.rear] = 1;
    while (Qu.front < Qu.rear) {
        Qu.front++;
        p = Qu.data[Qu.front];
        k = Qu.level[Qu.front];
        if (p->lchild != NULL) {
            Qu.rear++;
            Qu.data[Qu.rear] = p->lchild;
            Qu.level[Qu.rear] = k + 1;
        }
        if (p->rchild != NULL) {
            Qu.rear++;
            Qu.data[Qu.rear] = p->rchild;
            Qu.level[Qu.rear] = k + 1;
        }
    }  // while 结束

    max = 0;
    i = 0;
    k = 1;
    while (i <= Qu.rear) {
        n = 0;
        while (i <= Qu.rear && Qu.level[i] == k) {
            n++;
            i++;
        }
        k = Qu.level[i];
        if (n > max) max = n;
    }
    return max;
}