#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long G(long long n, int c, int d) {
    if (n == 0) return d;
    if (n == 1) return c;
    return (G(n - 1, c, d) + 2 * G(n - 2, c, d)) % MOD;
}

long long F(long long n, int a, int b, int c, int d) {
    if (n == 0) return b;
    if (n == 1) return a;
    return (3 * F(n - 1, a, b, c, d) + 2 * F(n - 2, a, b, c, d) + G(n, c, d) + G(n - 1, c, d) + G(n - 2, c, d)) % MOD;
}

int main() {
    int a, b, c, d;
    long long n;
    cin >> a >> b >> c >> d >> n;
    long long result = F(n, a, b, c, d);
    cout << result << endl;
    return 0;
}

// vẫn TLE chưa tối ưu được 