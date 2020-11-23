// 删除顺序表最小值,用最后个补位
bool delmin(SqlList &L, ElementType &value) {
    if (L.length == 0) {
        return false;
    }

    value = L.data[0];
    int pos = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }

    L.data[pos] = L.data[L.length - 1];
    L.length--;

}