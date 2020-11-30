#include <cstdio>
// two point
// 两个指针分别指向序列位序,当i+j=n-1 则是中位数
// O(n) T(1)
int function(int A[], int B[], int length) {
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

// 第二种方法 折半
int function2(int A[], int B[], int length) {
    int s1 = 0, d1 = length - 1, mid1, s2 = 0, d2 = length - 1, mid2;
    while (s1 != d1 || s2 != d2) {
        mid1 = (d1 - s1) / 2;
        mid2 = (d2 - s2) / 2;
        if (A[mid1] == B[mid2]) { // 两中位数字相等 直接返回
            return A[mid1];
        }
        if (A[mid1] < B[mid2]) {
            if ((s1 + d1) % 2 == 0) {  // 单个序列偶数
                s1 = mid1;
                d2 = mid2;
            } else {
                s1 = mid1 + 1;
                d2 = mid2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                d1 = mid1;
                s2 = mid2;
            } else {
                d2 = mid1;
                s2 = mid2 + 1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

int main() {
    int A[6] = {1, 2, 3, 5, 5, 6};
    int B[6] = {1, 2, 4, 4, 5, 6};
    printf("%d\n", function(A, B, 6));
    printf("%d", function2(A, B, 6));
    return 0;
}