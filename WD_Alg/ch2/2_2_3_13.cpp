// k空间换时间换空间
// n个数组 最多出现n个数字,最大不限,但最小一定出现在n以内
// 使用n+1大小的数组标记该位置序号是否出现过
// 最后遍历
// O(n) S(n)

int findmin(int A[], int n) {
    int i, *B;
    B = (int *)malloc(sizeof(int) * n);
    memset(B, 0, siezeof(int) * n);
    for (i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] < n) {
            B[A[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0) break;
    }

    return i + 1;
}