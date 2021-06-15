// 快速排序
#include <malloc.h>

#include <cstdio>
typedef int ElemType;

void quickSort(ElemType A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        quickSort(A, low, pivotpos - 1);
        quickSort(A, pivotpos + 1, high);
    }
}
int Partition(ElemType A[], int low, int high) {
    ElemType piovt = A[low];
    while (low < high) {
        while (low < high && A[high] > piovt) {
            high--;
        }
        while (low < high && A[low] > piovt) {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = piovt;
    return low;
}