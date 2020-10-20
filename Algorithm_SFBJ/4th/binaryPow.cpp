#include <cstdio>

using namespace std;

typedef long long LL;
//快速幂.a^b%m
LL binaryPow(LL a, LL b, LL m) {
    LL ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
int main() {
    printf("%d", binaryPow(12, 12,5));
    return 0;
}