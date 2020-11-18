// 第五章 树与二叉树
// 5.3.3 二 15
// 满二叉树 先序求后序
#include <malloc.h>

#include <cstdio>
#define MaxSize 50

typedef int ElemType;
// 二叉树
typedef struct BitNode {
    ElemType data;
    BitNode *lchild, *rchild;
} BitNode, *BitTree;

// 满二叉树 结点左右子树总结数相同
// 先序第一个结点是后序的最后一个结点
void function(ElemType pre[], int low1, int high1, ElemType post[], int low2,
              int high2) {
    int half;
    if (low1 < high1) {
        post[high2] = pre[low1];
        half = (high1 - low1 ) / 2;
        function(pre, low1 + 1, low1 + half, post, low2, low2 + half - 1);  // 左子树
        function(pre, low1 + half + 1, high1, post, low2 + half, high2 - 1);  // 左子树
    }
}