// 使用一辅助数组,长度和题目中顺序表中最大值一样,值全部致0
// 设置两指针,依次代表 顺序表位序,以及不重复数值位序
// 扫描顺序表过程中,数值第一次出现,则记录辅助数组中该值为1

// 有序顺序表
bool function2(SqlList &L) {
    int i = 0, j = 1;

    if (L.length == 0) {
        return false;
    }
    for (; j < L.length; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }

    L.length = i + 1;
    return true;
}

// 无序顺序表
void funtion(int A[], int n) {  // A顺序表,n为A长度
    int B[n - 1] = {0};
    int i = 0, j = 0;
    while (i < n) {
        if (B[A[i]] == 0) {
            B[A[i]] == 1;
            j++;
        }
        A[j] = A[i++];
    }
    A.length = j + 1;
}