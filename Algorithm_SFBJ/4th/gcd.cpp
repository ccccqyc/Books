// 最大公约数

int gcd(int a, int b) { 
    return !b ? a : gcd(b, a % b); }