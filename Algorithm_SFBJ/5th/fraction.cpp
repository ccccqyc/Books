#include <cmath>
#include <cstdio>

using namespace std;
struct Fraction {
    int up, down;
};
//最大公约数
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
//分数化简
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

//相加
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
//相减
Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
//乘法
Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f2.down * f1.down;
    return reduction(result);
}
//除法
Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction f) {
    f = reduction(f);

    if (f.down == 1) {
        printf("%lld", f.up);
    } else if (abs(f.up) > abs(f.down)) {
        printf("%d %d/%d", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%d/%d", f.up, f.down);
    }
}