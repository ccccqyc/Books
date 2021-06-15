// 数组内部 内部逆序
// 整体逆转顺序,然后左边,右边分别逆转顺序
typedef int DataType;

void reverse(DataType A[], int low, int high, int arrsize) {
    if (low > high || high > arrsize) {
        return;
    }

    DataType temp;
    for (int i = low; i <= (high - low) / 2; i++) {
        temp = A[i];
        A[i] = A[high - i];
        A[high - i] = temp;
    }
}

void Exchange(DataType A[], int m, int n, int length) {
    reverse(A, 0, m + n - 1, length);
    reverse(A, 0, n - 1, length);
    reverse(A, n, m + n - 1, length);
}