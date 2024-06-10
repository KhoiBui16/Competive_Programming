#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }
    void update(int index, int delta) {
        for (; index <= n; index += index & -index) {
            bit[index] += delta;
        }
    }
    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += bit[index];
        }
        return sum;
    }
    int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> H;
    H.reserve(2 * N); 
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        H.push_back(A[i]);
    }
    vector<int> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
        H.push_back(queries[i]);
    }
    sort(H.begin(), H.end());
    H.erase(unique(H.begin(), H.end()), H.end());
    unordered_map<int, int> C;
    C.reserve(H.size()); 

    for (int i = 0; i < H.size(); ++i) {
        C[H[i]] = i + 1; 
    }
    FenwickTree fenwick(H.size());
    for (int height : A) {
        int C_height = C[height]; 
        fenwick.update(C_height, 1);
    }
    for (int query : queries) {
        int C_query = C[query]; 
        int position = fenwick.query(C_query);
        cout << (position + 1) << endl;
        fenwick.update(C_query, 1);
    }
    return 0;
}

// đúng full 100/100 - 21/21 (test)