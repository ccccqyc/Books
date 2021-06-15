// 直接插入排序
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

// 王道版本
void InsertSort(ElemType A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; --j) {
                A[j + 1] = A[j];
                A[j + 1] = A[0];
            }
        }
    }
}

// 经典版本
void InsertSort2(ElemType A[]) {
    int len = A.length();
    int perIndex, current;
    for (int i = 1; i < len; i++) {
        perIndex = i - 1;
        current = A[i];
        while (perIndex >= 0 && A[perIndex] > current) {
            A[perIndex + 1] = A[perIndex];
            perIndex--;
        }
        A[perIndex + 1] = current;
    }
}