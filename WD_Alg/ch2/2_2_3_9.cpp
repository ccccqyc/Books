// 折半查找
typedef int DataType;

void function(DataType A[], DataType x) {
    int low = 0, high = A.length - 1, mid;
    while (low < high) {
        mid = (high - low) / 2;
        if (A[mid] == x) {
            break;
        } else if (A[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (A[mid] == x && mid != A.length - 1) {
        DataType temp = A[mid];
        A[mid] = A[mid - 1];
        A[mid] = temp;
    } else if (A[mid] != x) {
        int i;
        for (i = A.length - 1; i > high; i--) {
            A[i + 1] = A[i];
        }
        A[i] = x;
    }
}