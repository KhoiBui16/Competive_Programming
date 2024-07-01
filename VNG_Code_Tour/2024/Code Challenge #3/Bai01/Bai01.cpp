#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    int profit;
    int cost;
    vector<int> requirements;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Product> products(N);

    // Đọc lợi nhuận của từng sản phẩm
    for (int i = 0; i < N; ++i) {
        cin >> products[i].profit;
    }

    // Đọc chi phí sử dụng tài nguyên của từng sản phẩm
    for (int i = 0; i < N; ++i) {
        cin >> products[i].cost;
    }

    // Đọc ma trận yêu cầu sử dụng tài nguyên của từng sản phẩm
    for (int i = 0; i < N; ++i) {
        products[i].requirements.resize(M);
        for (int j = 0; j < M; ++j) {
            cin >> products[i].requirements[j];
        }
    }

    // Tạo mảng DP để lưu lợi nhuận tối đa có thể đạt được
    vector<long long> dp(M + 1, 0);
    vector<int> chosenProducts;

    // Duyệt qua từng sản phẩm
    for (int i = 0; i < N; ++i) {
        // Cập nhật DP từ phải sang trái để tránh overwrite giá trị cũ
        for (int j = M; j >= 0; --j) {
            if (j >= products[i].cost) { // Kiểm tra xem có thể chọn sản phẩm i hay không
                dp[j] = max(dp[j], dp[j - products[i].cost] + products[i].profit);
            }
        }
    }

    long long maxProfit = dp[M];

    // Tìm các sản phẩm được chọn để đạt lợi nhuận tối đa
    int remainingMoney = M;
    for (int i = N - 1; i >= 0; --i) {
        if (remainingMoney >= products[i].cost && dp[remainingMoney] == dp[remainingMoney - products[i].cost] + products[i].profit) {
            chosenProducts.push_back(i + 1); // Lưu lại chỉ số sản phẩm từ 1 đến N
            remainingMoney -= products[i].cost;
        }
    }

    // In ra lợi nhuận tối đa có thể đạt được
    cout << maxProfit << endl;

    // In ra danh sách các sản phẩm được chọn
    if (chosenProducts.empty()) {
        cout << "0\n";
    } else {
        for (int i = chosenProducts.size() - 1; i >= 0; --i) {
            cout << chosenProducts[i] << " ";
        }
        cout << endl;
    }

    // Tìm các tài nguyên được sử dụng
    vector<bool> usedResource(M, false);
    for (int i = 0; i < chosenProducts.size(); ++i) {
        for (int j = 0; j < M; ++j) {
            if (products[chosenProducts[i] - 1].requirements[j] == 1) {
                usedResource[j] = true;
            }
        }
    }

    // In ra danh sách các tài nguyên được sử dụng
    int usedCount = 0;
    for (int j = 0; j < M; ++j) {
        if (usedResource[j]) usedCount++;
    }

    if (usedCount == 0) {
        cout << "0\n";
    } else {
        for (int j = 0; j < M; ++j) {
            if (usedResource[j]) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
