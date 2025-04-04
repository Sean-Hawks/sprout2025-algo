#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 測試資料數量
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cout << "Line #" << t << "\n";

        int G; // 團體數量
        cin >> G;

        unordered_map<int, int> groupMap; // 記錄每個人屬於哪個群組
        for (int i = 0; i < G; ++i) {
            int K;
            cin >> K;
            while (K--) {
                int member;
                cin >> member;
                groupMap[member] = i; // 每個人的群組 ID
            }
        }

        int M; // 敘述數量
        cin >> M;

        queue<int> mainQueue; // 記錄隊伍內的群組順序
        unordered_map<int, queue<int>> groupQueues; // 各群組內部的排隊順序
        unordered_set<int> groupInQueue; // 記錄哪些群組目前在 mainQueue 內

        while (M--) {
            string cmd;
            cin >> cmd;

            if (cmd == "ENQUEUE") {
                int x;
                cin >> x;
                int groupID = (groupMap.count(x) ? groupMap[x] : -1);

                if (groupID == -1) {
                    // 這個人不屬於任何群組，獨立排隊
                    groupQueues[x] = queue<int>(); // 確保有 queue 可用
                    groupQueues[x].push(x);
                    mainQueue.push(x);
                    groupInQueue.insert(x);
                } else {
                    if (groupQueues[groupID].empty()) {
                        // 這個群組還沒有人排隊，先把群組加到 mainQueue
                        mainQueue.push(groupID);
                        groupInQueue.insert(groupID);
                    }
                    // 把這個人加到該群組的隊列
                    groupQueues[groupID].push(x);
                }
            } 
            else if (cmd == "DEQUEUE") {
                int frontGroup = mainQueue.front();

                int person;
                if (groupQueues.count(frontGroup) && !groupQueues[frontGroup].empty()) {
                    person = groupQueues[frontGroup].front();
                    groupQueues[frontGroup].pop();
                } else {
                    person = frontGroup;
                    mainQueue.pop();
                }

                cout << person << "\n";

                // 如果該群組沒人了，從 mainQueue 移除
                if (groupQueues.count(frontGroup) && groupQueues[frontGroup].empty()) {
                    mainQueue.pop();
                    groupInQueue.erase(frontGroup);
                }
            }
        }
    }
    return 0;
}
