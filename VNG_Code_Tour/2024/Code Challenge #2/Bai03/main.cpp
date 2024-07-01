#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    
    int m = s.size();
    int countValid = 0;
    string rotated = "";
    if (n > m) 
    {
        for (int i = 0; i < m; ++i) 
            rotated = s.substr(i) + s.substr(0, i);
            if (isValid(rotated)) 
                countValid++;
        
        int fullCycles = n / m;
        countValid *= fullCycles;
        
        int remaining = n % m;
        for (int i = 0; i < remaining; ++i) 
        {
            rotated = s.substr(i) + s.substr(0, i);
            if (isValid(rotated)) 
                countValid++;
        }
    } 
    else 
    {
        for (int i = 0; i < n; ++i) 
        {
            rotated = s.substr(i) + s.substr(0, i);
            if (isValid(rotated)) 
                countValid++;
        }
    }

    cout << countValid << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
