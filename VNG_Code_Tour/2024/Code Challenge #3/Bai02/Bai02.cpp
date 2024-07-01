#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Sắp xếp lại các chiều cao của các cột đá
    sort(heights.begin(), heights.end());

    // Tính tổng chiều dài của các tấm gỗ
    double totalLength = 0.0;
    for (int i = 1; i < n; ++i) {
        totalLength += sqrt(pow(heights[i] - heights[i - 1], 2) + 1);
    }

    // In ra tổng chiều dài nhỏ nhất của các tấm gỗ, làm tròn đến 6 chữ số thập phân
    cout << fixed;
    cout.precision(6);
    cout << totalLength << endl;

    return 0;
}
