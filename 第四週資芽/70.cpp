#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

struct Function {
    double a, b, c;
};

// 計算在時間 t 時，各題目中快感函數的最大值，也就是整場比賽的樂趣度 F(t)
double computeF(double t, const vector<Function>& funcs) {
    double maxVal = -1e18;
    for (const auto& func : funcs) {
        double value = func.a * (t - func.b) * (t - func.b) + func.c;
        if (value > maxVal)
            maxVal = value;
    }
    return maxVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Function> funcs(n);
        for (int i = 0; i < n; i++) {
            cin >> funcs[i].a >> funcs[i].b >> funcs[i].c;
        }
        
        // 設定時間區間 [0, 300]
        double low = 0.0, high = 300.0;
        // 由於 F(t) 為凸函數，因此可以用三分搜尋法找到全域最小值
        for (int i = 0; i < 100; i++) { // 迭代次數足以收斂
            double m1 = low + (high - low) / 3.0;
            double m2 = high - (high - low) / 3.0;
            double f1 = computeF(m1, funcs);
            double f2 = computeF(m2, funcs);
            // 根據 f1 與 f2 的比較，縮小搜尋區間
            if (f1 > f2)
                low = m1;
            else
                high = m2;
        }
        // 最佳答案取 (low + high)/2 時的 F 值
        double ans = computeF((low + high) / 2.0, funcs);
        cout << fixed << setprecision(12) << ans << "\n";
    }
    
    return 0;
}

// credit by gpt