#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> points(4);
    set<pair<int, int>> uniquePoints;

    for (int i = 0; i < 4; ++i) {
        cin >> points[i].first >> points[i].second;
        uniquePoints.insert(points[i]);
    }

    // Kiểm tra trùng điểm
    if (uniquePoints.size() < 4) {
        cout << -1 << endl;
        return 0;
    }

    set<int> xs, ys;
    for (auto p : points) {
        xs.insert(p.first);
        ys.insert(p.second);
    }

    // Phải có đúng 2 x khác nhau và 2 y khác nhau
    if (xs.size() != 2 || ys.size() != 2) {
        cout << "NO" << endl;
        return 0;
    }

    // Lấy ra 2 giá trị x và y
    vector<int> x_vals(xs.begin(), xs.end());
    vector<int> y_vals(ys.begin(), ys.end());

    // Tạo tập hợp 4 điểm cần có nếu là hình vuông
    set<pair<int, int>> squareCorners = {
        {x_vals[0], y_vals[0]},
        {x_vals[0], y_vals[1]},
        {x_vals[1], y_vals[0]},
        {x_vals[1], y_vals[1]}
    };

    // So sánh tập điểm
    if (uniquePoints == squareCorners) {
        // Kiểm tra chiều dài cạnh phải bằng nhau
        if (abs(x_vals[0] - x_vals[1]) == abs(y_vals[0] - y_vals[1])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
