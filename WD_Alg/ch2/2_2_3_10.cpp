// 将数组内部置换顺序,前n-p+1 ,p-1个分别置换
void reverse(int A[], int low, int high) {
    int temp;
    // 颠倒顺序
    for (int i = low; i < high / 2; i++) {
        temp = A[i];
        A[i] = A[high - i];
        A[high - i] = temp;
    }
}
// 传入参数 数组,数组长度,移动位置
// Tn = O(n); Sn=O(1)
void function(int A[], int length, int p) {
    reverse(A, 0, length - 1);
    reverse(A, 0, p - 1);
    reverse(A, p, length - 1);
}