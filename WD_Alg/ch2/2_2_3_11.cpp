// two point
// 两个指针分别指向序列位序,当i+j=n-1 则是中位数
// O(n) T(1)
int fuction(int A[], int B[], int length) {
    int i = 0, j = 0;
    while (i + j < length - 1) {
        if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (A[i] < B[j]) {
        return A[i];
    } else {
        return B[j];
    }
}

// 第二种方法