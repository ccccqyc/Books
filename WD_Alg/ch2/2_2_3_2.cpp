// 逆序顺序表 要求空间O(1)
void funtion(SqlList &L) {
    int temp = L.data[0];
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}