#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int t, n;
    cin >> t;
    bool check = true;
    ll power = 1;
    while (t--) {
        cin >> n;
        vector<ll> monster(n);
        for (int i = 0; i < n; i++) {
            cin >> monster[i];
        }
        sort(monster.begin(), monster.end());
        for (int i = 0; i < n; i++) {
            if (power >= monster[i]) {
                power += monster[i];
            } else {
                check = false;
                break;
            }
        }
        if (check) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        monster.clear();
        check = true;
        power = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

// đúng 16/51 (test)