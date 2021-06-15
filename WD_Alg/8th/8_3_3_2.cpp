// 双冒泡
void BubbleSort(int A[], int n) {
    // 双向起泡.排序,交替进行正反两个方向的起泡过程
    int low = 0, high = n - 1;
    bool flag = true;
    while (low < high && flag) {
        flag = false;
        for (i = low; i < high; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);  //交换
                flag = true;           // 置flag
            }
        }
        high--;

        for (i = high; i > low; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                flag = true;  //置flag
            }
        }
        low++;
    }
}