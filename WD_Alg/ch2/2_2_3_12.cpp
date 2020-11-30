// 求众数
// 使用摩尔投票法. 设置一值记录当前候选众数,一值计数
// 扫描数组,如果计数为0则设置当前值为候选众数
// 如果计数大于0,扫描数组和候选众数相等计数加1 否则减一
// 扫描结束
// 如果计数大于0,再扫描一次,从零开始的计数如果大于等于一半则是众数,否则不是.
int function(int A[], int length) {
    int temp, count = 0;
    for (int i = 0; i < length; i++) {
        if (count == 0) {
            temp = A[i];
            count++;
            continue;
        }
        if (temp == A[i]) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int i = 0; i < length; i++) {
        if (temp == A[i]) {
            count++;
        }
        if ((count >= (length / 2 + 1)) && (length % 2 == 1)) {
            return temp;
        } else if ((count >= length / 2) && (length % 2 == 0)) {
            return temp;
        }
    }
    return -1;
}