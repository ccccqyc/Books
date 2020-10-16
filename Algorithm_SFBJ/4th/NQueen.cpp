#include <cmath>
#include <cstdio>
const int MAXN = 11;
using namespace std;
int n, P[MAXN], hashTable[MAXN] = {false};
int count = 0;
// N皇后 全排列暴力解法
void generate(int index) {
    bool flag;
    if (index == n + 1) {
        flag = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (abs(i - j) == abs(P[i] - P[j])) {
                    flag = false;
                    goto first;
                }
            }
        }
    first:
        if (flag) count++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!hashTable[i]) {
            P[index] = i;
            hashTable[i] = true;
            generate(index + 1);
            hashTable[index] = false;
        }
    }
}