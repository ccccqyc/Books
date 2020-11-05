// 第五章 树与二叉树
// 5.3.3 二 8
// 给定二叉树,确定双分支结点个数.
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 思路 层序遍历
// 弹出后 看结点子结点数

int function(BitTree T) {
    BitNode *p = T;
    Queue Q;
    if (T == NULL) return 0;
    InitQueue(Q);
    Enqueue(Q, p);
    int count = 0;
    whlie(!isEmpty(Q)) {
        DeQueue(Q, p);
        if (p->rchild != NULL && p->lchild != NULL) count++;
        EnQueue(Q, p->rchild);
        EnQueue(Q, p->lchild);
    }
    return count;
}

// 递归实现
// T=null return 0
// T双结点均存在 return f(T->rchlid)+f(T->lchild)+1
// 其他情况 return f(T->rchlid)+f(T->lchild)
int DsonNodes(BitTree T) {
    if (T == NULL) return 0;
    if (T->rchild != NULL && T->lchild != NULL) {
        return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
    } else {
        return DsonNodes(T->lchild) + DsonNodes(T->rchild);
    }
}