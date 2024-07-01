#include <bits/stdc++.h>
using namespace std;
bool HopLe(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
            if (balance < 0) return false;
        }
    }
    return balance == 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    deque<char> dq(S.begin(), S.end());
    unordered_set<string> xoay;
    for (int i = 0; i < N; ++i) {
        string x(dq.begin(), dq.end());
        if (HopLe(x)) {
            xoay.insert(x);
        }
        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    cout << xoay.size();
    return 0;
}

