#include <cstdio>
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 *  在一个长度为n整数序列中，奇数元素和偶数元素各占一半，存放
在数组A[n]中。请设计一个时间和空间尽可能高效的算法NewSequence
(int A[]，intn), 重新安排这些整数，使奇数元素存放在奇数单元，偶数
元素存放在偶数单元，并说明算法的时间和空间复杂度。
 * */
void thenewSequence(int arr[], int n) {
    int i = 0, j = 1;
    while (i <= n - 2 || j <= n - 1) {
        if (arr[i] % 2 == 1) {  //奇数 1^1 = 1
            i += 2;
        }
        // if (arr[i] ^ 1 == 1) {  //奇数 1^1 = 1
        //     i += 2;
        // }
        if (arr[j] % 2 == 0) {  //偶数
            j += 2;
        }
        if (arr[i] % 2 == 0 && arr[j] % 2 == 1) {
            swap(arr, i, j);
            i += 2;
            j += 2;
        }
    }
}

int main() {
    int arr[6] = {1, 3, 5, 2, 4, 6};
    printf("%d ", 1 ^ 0);

    thenewSequence(arr, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
