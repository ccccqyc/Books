// 遍历二叉树
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

//递归 先序 后序 中序
void preOrder1(BitTree T) {
    if (T) {
        visit(T);
        preOrder1(T->lchild);
        preOrder1(T->rchild);
    }
}
void PostOrder1(BitTree T) {
    if (T) {
        preOrder1(T->lchild);
        preOrder1(T->rchild);
        visit(T);
    }
}
void inOrder1(BitTree T) {
    if (T) {
        preOrder1(T->lchild);
        visit(T);
        preOrder1(T->rchild);
    }
}

//非递归 先序
void preorder(BitTree T) {
    Stack S;
    InitStack(S);  //初始化栈

    BitNode *p = T;
    while (p || !isEmpty(S)) {  //栈不空
        if (p) {
            visit(p);
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            p = p->rchild;
        }
    }
}
//非递归 中序
void inorder(BitTree T) {
    Stack S;
    InitStack(S);  //初始化栈
    BitNode *p = T;
    while (p || !isEmpty(S)) {  //栈不空
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            visit(p);
            p = p->rchild;
        }
    }
}

// 非递归 后序 双栈
void postOrder(BitTree T) {
    Stack S1;
    Stack S2;
    initStack(S1);
    initStack(S2);
    BitNode *p = T;
    // S1 用于遍历,S2用于存储 入S2栈顺序 根-右-左
    while (p && !isEmpty(S1)) {
        if (p) {
            push(S2, p);
            Push(S1, p);
            p = p->rchild;
        } else {
            Pop(S1, p);
            p = p->lchild;
        }
    }

    while (!isEmpty(S2)) {
        Pop(S2, p);
        visit(p);
    }
}

//非递归 后序 单栈
void PostOrder2(BitTree T) {
    Stack S;
    initStack(S);

    BitNode *cur = T;
    BitNode *pre = NULL;
    while (cur != NULL || !isEmpty(S)) {
        while (cur) {
            Push(S, cur);
            cur = cur->lchild;
        }

        if (!isEmpty(S)) {
            pop(S, cur);
            if (cur->lchild == NULL && pre == cur->rchild) {
                visit(cur);
                pre = cur;
                cur = NULL;
            } else {
                Push(S, cur);
                cur = cur->rchild;
            }
        }
    }
}
// 层序
void LevelOrder(BitTree T) {
    Queue Q;
    InitQueue(Q);
    BitNode *p = T;
    EnQueue(Q, p);
    while (!isEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild) EnQueue(Q, p->lchild);
        if (p->rchild) EnQueue(Q, p->rchild);
    }
}
