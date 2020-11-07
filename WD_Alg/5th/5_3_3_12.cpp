// 第五章 树与二叉树
// 5.3.3 二 12
// 打印值为x结点祖先
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 思路后续遍历,查询到x值的结点,终止遍历,输出队列中祖先
void search(BitTree T, ElemType x) {
    Queue Q;
    initQueue(Q);  //初始化遍历队列.
    BitNode *p = T;
    if (T == NULL) return;
    if (isEmpty(Q) || p != NULL) {
        while (p != NULL && p->data != x) {
            EnQueue(Q, p);
            p = p->lchild;
        }
        //找到结点
        if (p->data == x && !isEmpty(Q)) {
            do {
                DeQueue(Q, p);  //出队
                printf("%d", p->data);
            } while (!isEmpty(Q));
            exit(1);
        }
    }
}