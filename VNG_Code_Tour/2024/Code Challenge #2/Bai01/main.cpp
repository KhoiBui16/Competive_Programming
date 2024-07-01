#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct HS {
    long tg, nangluc;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<HS> ds(n);

    // Đọc và lưu dữ liệu cán bộ
    for (int i = 0; i < n; ++i) {
        cin >> ds[i].tg >> ds[i].nangluc;
    }

    // Sắp xếp danh sách theo nangluc
    sort(ds.begin(), ds.end(), [](const HS& a, const HS& b) {
        return a.nangluc < b.nangluc;
    });

    // Tính tổng prefix_sum cho tg
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + ds[i - 1].tg;
    }

    // Xử lý các truy vấn
    while (q--) {
        ll xi;
        cin >> xi;

        // Binary search để tìm vị trí cuối cùng mà nangluc <= xi
        int lo = 0, hi = n - 1, pos = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ds[mid].nangluc <= xi) {
                pos = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // Tính tổng tg cho các cán bộ có nangluc <= xi
        ll sumTime = (pos == -1 ? 0 : prefix_sum[pos + 1]);

        // In kết quả
        cout << sumTime << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// dùng prefix sum fulltest