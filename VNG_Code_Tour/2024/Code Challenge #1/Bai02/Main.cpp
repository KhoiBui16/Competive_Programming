#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    int step = 0;
    if (n % k == 0) {
        step = n / k;
    }
    else {
        step = n / k + 1;
    }
    ll sum = 0;
    for (int i = 1; i <= step; i++)
        sum += i;
    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
