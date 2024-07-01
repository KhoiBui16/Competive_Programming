#include <bits/stdc++.h>
using namespace std;
void prime(int num, map<int, int>& f) {
    while (num % 2 == 0) {
        f[2]++;
        num /= 2;
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            f[i]++;
            num /= i;
        }
    }
    if (num > 2) f[num]++;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    map<int, int> sumf;
    for (int i = 0; i < N; ++i) prime(a[i], sumf);
    int T;
    cin >> T;
    vector<pair<int, int>> q(T);
    for (int i = 0; i < T; ++i) cin >> q[i].first >> q[i].second;
    string kq = "";
    for (int i = 0; i < T; ++i) {
        int X = q[i].first;
        int P = q[i].second;
        map<int, int> qf;
        prime(X, qf);
        bool hople = 1;
        for (const auto& f : qf) {
            if (sumf[f.first] < f.second * P) {
                hople = 0;
                break;
            }
        }
        kq += (hople ? '1' : '0');
    }
    cout << kq;
    return 0;
}