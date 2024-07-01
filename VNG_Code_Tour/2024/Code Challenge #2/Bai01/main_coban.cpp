#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct HS
{
    long tg, nangluc;
};

int n, q;
vector<HS> ds;
long xi, ai, bi;
long long sumTime;


void solve()
{
    cin >> n >> q;
    ds.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ai >> bi;
        ds.push_back({ai, bi});
    }
    sort(ds.begin(), ds.end(), [](const HS& a, const HS& b)
    {
        return a.nangluc < b.nangluc;
    });

    while (q--)
    {
        cin >> xi;
        for (const auto& it : ds)
        {
            if (xi >= it.nangluc)
                sumTime += it.tg;
        }
        cout << sumTime << endl;
        sumTime = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

// giải được 14/21 test còn lại bị TLE