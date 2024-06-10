#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> ropes(N);
    for (int i = 0; i < N; ++i) {
        cin >> ropes[i];
    }

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    int jumps = 0, farthest = 0, current_end = 0;

    for (int i = 0; i < N; ++i) {
        if (i > farthest) {
            cout << "CANNOT GET DESTINATION" << endl;
            return 0;
        }

        farthest = max(farthest, i + ropes[i]);

        if (i == current_end) {
            jumps++;
            current_end = farthest;

            if (current_end >= N) {
                cout << jumps << endl;
                return 0;
            }
        }
    }

    cout << "CANNOT GET DESTINATION" << endl;
    return 0;
}