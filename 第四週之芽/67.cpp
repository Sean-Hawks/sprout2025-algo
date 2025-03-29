#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// 全域變數：儲存你馬匹的資料與對手馬匹的速度
vector<pair<ll,ll>> myHorses; // (a, b)
vector<ll> oppHorses;         // 對手馬匹速度

// n: 馬匹數量, T: 訓練天數
// 此函式計算在訓練 T 天後，利用最佳出賽順序所能取得的最大勝場數。
int winsWithTraining(ll T, int n) {
    // 計算每匹你的馬在 T 天後的速度：speed = a + T * b
    vector<ll> speeds(n);
    for (int i = 0; i < n; i++) {
        speeds[i] = myHorses[i].first + T * myHorses[i].second;
    }
    sort(speeds.begin(), speeds.end()); // 升冪排序
    
    // 由於對手的出賽順序是固定的，
    // 我們先將對手馬匹的速度也排序(升冪排序)，
    // 利用貪心策略：用速度剛好能勝出的馬匹對抗對手的馬匹
    int wins = 0;
    int i = 0, j = 0;
    int oppSize = n;
    while(i < n && j < oppSize) {
        if(speeds[i] > oppHorses[j]) {
            wins++; // 這場比賽獲勝
            i++;
            j++;
        } else {
            // 此馬無法勝過對手目前的馬，捨棄，嘗試下一匹
            i++;
        }
    }
    return wins;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Tcase;
    cin >> Tcase;
    while(Tcase--) {
        int n, M; // n: 馬匹數量, M: 至少要贏的場數
        cin >> n >> M;
        
        myHorses.resize(n);
        for (int i = 0; i < n; i++){
            ll a, b;
            cin >> a >> b;
            myHorses[i] = {a, b};
        }
        
        oppHorses.resize(n);
        for (int i = 0; i < n; i++){
            cin >> oppHorses[i];
        }
        // 由於對手的出賽順序固定：第一場用最快，第二場次快……，
        // 我們將對手的馬匹速度升冪排序後，在貪心匹配時從最小開始比較
        sort(oppHorses.begin(), oppHorses.end());
        
        // 若 M 超過 n，不可能贏 M 場，直接輸出 -1
        if(M > n) {
            cout << -1 << "\n";
            continue;
        }
        
        // 先檢查 T = 0 的情況
        if(winsWithTraining(0, n) >= M) {
            cout << 0 << "\n";
            continue;
        }
        
        // 檢查若所有馬的成長率皆為 0，則速度不會改變，永遠無法改善勝場數
        bool anyGrowth = false;
        for (int i = 0; i < n; i++){
            if(myHorses[i].second > 0) {
                anyGrowth = true;
                break;
            }
        }
        if(!anyGrowth) {
            cout << -1 << "\n";
            continue;
        }
        
        // 二分搜尋 T 的範圍：先用倍增找出一個上界 high，使得勝場數 >= M
        ll low = 0, high = 1;
        while(high < (ll)1e18 && winsWithTraining(high, n) < M) {
            high *= 2;
        }
        // 如果高值太大仍然無法達標，代表無解
        if(winsWithTraining(high, n) < M) {
            cout << -1 << "\n";
            continue;
        }
        
        // 二分搜尋找出最小 T 使得 winsWithTraining(T) >= M
        ll ans = high;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            int w = winsWithTraining(mid, n);
            if(w >= M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}

// credited by gpt