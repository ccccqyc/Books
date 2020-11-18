
// 第五章 树与二叉树
// 5.3.3 二 16
// 将任意二叉树叶节点串成链表
#include <malloc.h>

#include <cstdio>
#define MaxSize 50

typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

//链表
typedef struct LinkNode {
    int data;
    LinkNode *next;
} LNode, *LinkList;

// 思路 先序遍历,碰到左右结点皆为空的结点
// 加入到叶结点链表中
// 设置辅助指针 pre 作为指向尾结点
void function(BitTree T, BitNode *head) {
    BitNode *p = T, *pre = NULL;
    Stack S;
    initStack(S);

    while (p || !isEmpty(S)) {
        if (p->lchild) {
            push(S, p);
            p = p->lchild;
        } else {
            if (p->rchild == NULL) {
                if (pre == NULL) {  // 第一次插入
                    head->rchild = p;
                    pre = p;
                } else {
                    pre->rchild = p;
                    pre = p;
                }
            }
            pop(S, p);

            p = p->rchild;
        }
    }
}