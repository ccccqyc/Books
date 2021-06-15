
// 第五章 树与二叉树
// 5.3.3 二 13
// 寻找最近祖先
#include <cstdio>
typedef int ElemType;

// 二叉树
typedef struct BitNode {
    ElemType INFO;
    BitNode *LLINK, *RLINK;
} BitNode, *BitTree;
//思路 利用双栈实现后序遍历
// 后序遍历中弹出一个点分别对比p,q直到两个点都被确认
// 剩余栈中的第一个就是最近祖先
void ANCESTOR(BitTree Root, BitNode *p, BitNode *q, BitNode &r) {
    Satck S1, S2;
    initStack(S1);
    initStack(S2);  // 记录后序
    BitNode *temp = Root;
    //双栈实现后序遍历
    while (temp != NULL || !isEmpty(S1)) {
        if (temp != NULL) {
            Push(S2, temp);
            Push(S1, temp);
            temp = temp->RLINK;
        } else {
            Pop(S1, temp);
            temp = temp->LLINK;
        }
    }
    // 利用计数器 count 实现终止查找
    int count = 2;
    while (!isEmpty(S2)) {
        Pop(S2, temp);
        if (temp == p || temp == q) {
            count--;
        }
        if (count == 0) {
            Pop(S2, r);
            break;
        }
    }
}