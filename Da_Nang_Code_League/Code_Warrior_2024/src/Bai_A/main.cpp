#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = (ll)(1e9+7);
int n;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

long long calculate_weight(const string s) {
    long long cnt = 0;
    long long total_weight = 0;
    for (char c : s) {
        if (c == '#') cnt++;
        else
        {
            if (cnt > 0) {
                total_weight = (total_weight% mod + binpow(cnt, cnt)% mod) % mod;
                cnt = 0;
            }
        }
    }
    if (cnt > 0) {
        total_weight = (total_weight%mod + binpow(cnt, cnt)% mod) % mod;
    }
    return total_weight;
}

void sol()
{
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> grid[i][j];
    long long maxRow = 0, maxCol = 0;
    for (int i=0; i<n; i++)
    {
        string s;
        for (int j=0; j<n; j++)
        {
            s += grid[i][j];
        }
        maxRow = max(maxRow, calculate_weight(s));
    }
    for (int i=0; i<n; i++)
    {
        string s;
        for (int j=0; j<n; j++)
        {
            s += grid[j][i];
        }
        maxCol = max(maxCol, calculate_weight(s));
    }
    cout << maxRow << " " << maxCol;
}

int main()
{
    init();
    sol();
}
