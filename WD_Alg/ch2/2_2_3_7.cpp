// 扫描依次对比,两指针达到边界即停止

SqlList *function(SqlList &L1, SqlList &L2, SqlList &L3) {
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j]) {
            L3.data[k++] = L1.data[i];
        } else {
            L3.data[k++] = L2.data[j];
        }
    }
    while (i < L1.length) {
        L3.data[k++] = L1.data[i++];
    }
    while (j < L2.length) {
        L3.data[k++] = L2.data[j++];
    }

    L3.length = k + 1;
    return L3;
}