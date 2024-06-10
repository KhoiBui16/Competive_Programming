#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> position;
    vector<int> line(n);
    for (int i = 0; i < n; i++) {
        cin >> line[i];
        position[line[i]] = i + 1;
    }

    while (q--) {
        int x;
        cin >> x;
        vector<int>::iterator pos = upper_bound(line.begin(), line.end(), x);
        cout << (pos - line.begin() + 1) << endl;
        for (vector<int>::iterator it = pos; it != line.end(); ++it) {
            position[*it]++;
        }
        line.insert(pos, x);
        position[x] = pos - line.begin() + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

//* chỉ đúng 50/100: 12/21 (test)