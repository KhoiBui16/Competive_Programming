#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<pair<int, int>> events(m);
    vector<pair<int, int>> makeups(n);

    // Đọc thông tin về sự kiện
    for (int i = 0; i < m; ++i) {
        cin >> events[i].first >> events[i].second;
    }

    // Đọc thông tin về các cách trang điểm
    for (int i = 0; i < n; ++i) {
        cin >> makeups[i].first >> makeups[i].second;
    }

    // Sắp xếp danh sách các sự kiện theo thời điểm bắt đầu
    sort(events.begin(), events.end());

    int maxEvents = 0;

    // Duyệt qua từng cách trang điểm
    for (int makeupIdx = 0; makeupIdx < n; ++makeupIdx) {
        int start_effective = makeups[makeupIdx].first;
        int end_effective = makeups[makeupIdx].second;

        // Tìm vị trí đầu tiên của sự kiện có thời điểm bắt đầu >= start_effective
        auto it = lower_bound(events.begin(), events.end(), make_pair(start_effective, 0));

        // Đếm số sự kiện có thời điểm bắt đầu và kết thúc nằm trong khoảng thời gian hiệu quả của cách trang điểm
        int count = 0;
        while (it != events.end() && it->first <= end_effective) {
            if (it->second <= end_effective) {
                count++;
            }
            it++;
        }

        // Cập nhật số sự kiện nhiều nhất có thể tham gia
        maxEvents = max(maxEvents, count);
    }

    // In ra kết quả là số sự kiện nhiều nhất có thể tham gia
    cout << maxEvents << endl;

    return 0;
}
