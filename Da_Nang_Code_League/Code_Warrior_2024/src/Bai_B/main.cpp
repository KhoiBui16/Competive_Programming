#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void xuly_yeucau(int N, int R, int Q, double P, vector<pair<int, int>>& yeucau) {
    sort(yeucau.begin(), yeucau.end());
    priority_queue<int, vector<int>, greater<int>> thoi_gian_tra;
    int so_yeucau_khongduocdapung = 0;
    for (const auto& yc : yeucau) {
        int batdau = yc.first;
        int ketthuc = yc.second;
        while (!thoi_gian_tra.empty() && thoi_gian_tra.top() <= batdau) {
            thoi_gian_tra.pop();
            Q++;
        }
        if (Q > 0) {
            Q--;
            thoi_gian_tra.push(ketthuc);
        } else {
            so_yeucau_khongduocdapung++;
        }
    }
    double ti_le_khongduocdapung = (double(so_yeucau_khongduocdapung) / R) * 100;
    cout << R - so_yeucau_khongduocdapung << "/" << R << ": ";
    if (ti_le_khongduocdapung > P) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, R, Q;
    double P;
    cin >> N >> R >> Q >> P;
    vector<pair<int, int>> yeucau(R);
    for (int i = 0; i < R; ++i) {
        int Si, Fi;
        cin >> Si >> Fi;
        yeucau[i] = make_pair(Si, Fi);
    }
    xuly_yeucau(N, R, Q, P, yeucau);
    return 0;
}
