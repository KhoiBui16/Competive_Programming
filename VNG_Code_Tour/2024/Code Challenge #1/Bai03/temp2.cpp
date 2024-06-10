#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500005;

void solve() {
    int n, q;
    cin >> n >> q;
    int line[MAXN];
    for (int i = 0; i < n; i++) 
        cin >> line[i];
    while (q--) {
        int x;
        cin >> x;
        int pos = upper_bound(line, line + n, x) - line;
        cout << (pos + 1) << endl;
        for (int i = n; i > pos; i--) {
            line[i] = line[i - 1];
        }
        line[pos] = x;
        n++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

//* chỉ đúng 60/100: 13/21 (test)

