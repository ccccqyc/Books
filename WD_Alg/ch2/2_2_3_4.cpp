bool function(int A[], int s, int t) {
    int count = 0;
    if (s >= t || A.length == 0) {
        return false;
    }
    int j = 0;
    for (int i = 0; i < A.length; i++) {
        if (A[i] > s && A[i] < t) {
            count++;
        } else {
            a[j] = a[i];
            j++;
        }
    }
    A.length = A.length - count;
    return true;
}