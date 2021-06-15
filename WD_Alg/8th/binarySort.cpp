// 折半插入排序
#include <malloc.h>

#include <cstdio>
typedef int ElemType;
// 含哨兵 A[0]
// 参与排序的是 A[1]-A[n]
// 时间复杂度 O(n^2),算法稳定,适合数据量小
// 比较次数与初始状态无关,为O(nlogn) 
// 移动次数与初始状态有关
void binarySort(ElemType A[], int n) {
    int i, j, low, high, mid;
    // 比较和移动分离
    for (i = 2; i <= n; i++) {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        // 比较 找到移动位置
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[0] < A[mid])
                high = mid - 1;
            else {
                low = mid + 1;
            }
        }
        // 统一后移
        for (j = i - 1; j >= high + 1; --j) {
            A[j - 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}