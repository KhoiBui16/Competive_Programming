#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll power(ll a, ll b, ll mod) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

ll modInverse(ll a, ll p) {
    return power(a, p - 2, p);
}

ll findCubeRoot(ll C, ll N) {
    ll X = round(pow(C, 1.0 / 3.0));
    while (true) {
        if ((X * X * X) % N == C % N) {
            return X;
        }
        X++;
    }
}

void solve(){
    int K;
    cin >> K;
    vector<ll> primes(K);
    for (int i = 0; i < K; ++i) {
        cin >> primes[i];
    }
    ll C;
    cin >> C;
    ll N = 1;
    for (int i = 0; i < K; ++i) {
        N *= primes[i];
    }
    ll X = findCubeRoot(C, N);
    cout << X << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
