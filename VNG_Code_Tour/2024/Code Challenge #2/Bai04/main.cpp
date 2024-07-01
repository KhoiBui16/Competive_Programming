#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    
    vector<char> cardA(n), cardB(n);
    map<char, int> freqA;

    for (int i = 0; i < n; i++) {
        cin >> cardA[i];
        freqA[cardA[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> cardB[i];
    }

    ll pointA = 0, pointB = 0;

    for (int i = 0; i < n; i++) {
        char b = cardB[i];
        if (b == 'R') 
        {
            if (freqA['P'] > 0) {
                pointA++;
                freqA['P']--;
            } 
            else if (freqA['R'] > 0){
                freqA['R']--;
            }
            else
            {
                pointB++;
                freqA['S']--;
            }
        } 
        else if (b == 'P') 
        {
            if (freqA['S'] > 0)
            {
                pointA++;
                freqA['S']--;
            } 
            else if (freqA['P'] > 0)
                freqA['P']--;
            else 
            {
                pointB++;
                freqA['R']--;
            }
        } 
        else 
        { // b == 'S'
            if (freqA['R'] > 0) 
            {
                pointA++;
                freqA['R']--;
            }
            else if (freqA['S'] > 0)
                freqA['S']--; 
            else 
            {
                pointB++;
                freqA['P']--;
            }
        }
    }

    cout << pointA - pointB << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
