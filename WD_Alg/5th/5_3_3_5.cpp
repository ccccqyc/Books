// 第五章 树与二叉树
// 5.3.3 二 5
// 非递归求二叉树高度/深度.
#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 递归
int high(BitTree T) {
    BitNode *p = T;
    int count = 0;
    if (p == NULL) {
        return count;
    }

    int lhigh = high(p->lchild);
    int rhigh = high(p->rchild);
    return lhigh > rhigh ? lhigh + 1 : rhigh + 1;
}
//非递归

//拓展 二叉树宽度
int width(BitTree T) {
    if (T == NULL) {
        return 0;
    }
    Queue Q;
    initQueue(Q);
    int nWidth = 1;
    int nCurrentLevelWidth = 1;
    BitNode *p = T;

    while (!isEmpty(Q)) {
        while (nCurrentLevelWidth != 0) {
            DeQueue(Q, p);
            if (p->lchild != NULL) EnQueue(Q, p->lchild);
            if (p->rchild != NULL) EnQueue(Q, p->rchild);
            nCurrentLevelWidth--;
        }
        nCurrentLevelWidth = Q.size();
        nWidth = nCurrentLevelWidth > nWidth ? nCurrentLevelWidth : nWidth;
    }
    return nWidth;
}