// 第五章 树与二叉树
// 5.3.3 二 19
// 求二叉树带权路径和WSL
#include <malloc.h>

#include <cstdio>
#define MaxSize 50

typedef int ElemType;
// 二叉树
typedef struct BitNode {
    int weight;
    BitNode *left, *right;
} BitNode, *BitTree;

//思路 遍历,将二叉树
// 先序遍历.累计wpl
int wpl(BitTree root) { return function(root, 1); }
int function(BitTree root, int deep) {
    static int wpl = 0;
    if (root->left == NULL && root->right == NULL) {
        wpl += deep * root->weight;
    }
    if (root->left != NULL) {
        function(root->left, deep + 1);
    }
    if (root->right != NULL) {
        function(root->right, deep + 1);
    }
    return wpl;
}