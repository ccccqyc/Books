#include <cstdio>

using namespace std;
const int maxn = 11;
int n, P[maxn], hashTbale[maxn] = {false};
void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (hashTbale[x] == false) {
            P[index] = x;
            hashTbale[x] = true;
            generateP(index + 1);
            hashTbale[x] = false;
        }
    }
}

int main() {
    n =2;
    generateP(1);
    return 0;
}