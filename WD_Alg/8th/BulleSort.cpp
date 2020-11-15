// 冒泡排序
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

bool flag = false;
// 时间复杂度 O(n^2)空间复杂度 O(1) 稳定
void BulleSort(ElemType A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = n - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
            if (!flag) {
                return;
            }
        }
    }
}