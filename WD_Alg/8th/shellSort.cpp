// 希尔排序
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 时间复杂度 O(n^2),空间复杂度 O(1) 不稳定
// 适合基本有序,数据量少的排序
// 仅适用于 线性表为顺序存储的情况
void shellSort(ElemType A[], int n) {
    int dk, i, j;  // dk 步长
    for (dk = n / 2; n >= 1; dk = dk / 2) {
        for (i = dk + 1; i <= n; i++) {
            A[0] = A[i];
            for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk) {
                A[j + dk] = A[j];
            }
            A[j + dk] = A[0];
        }
    }
}

void shellSort(ElemType arr[]) {
    int len = arr.length;
    int gap, i, j;
    ElemType current;
    for (gap = len / 2; gap > 0; gap = gap / 2) {
        for (i = gap; i < len; i++) {
            j = i;
            current = arr[i];
            //比较移动
            while (j - gap >= 0 && current < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = current;
        }
    }
}