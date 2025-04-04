#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        // 建立鄰接串列：樹的節點編號從 0 到 N-1
        vector<vector<int>> tree(N);
        for(int i = 0; i < N - 1; i++){
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        // 用 DFS 計算每個節點的子樹大小，同時記錄每個節點的父節點
        vector<int> subtree(N, 0);
        vector<int> parent(N, -1);
        function<void(int, int)> dfs = [&](int node, int par){
            parent[node] = par;
            subtree[node] = 1;  // 自己也算一個
            for(auto next : tree[node]){
                if(next == par) continue; // 避免走回父節點
                dfs(next, node);
                subtree[node] += subtree[next];
            }
        };
        dfs(0, -1);  // 從 0 節點開始 DFS
        
        // 計算拔除每個節點後形成各部分的最大子樹大小（慘度）
        int centroid = 0;
        int best = N;  // 慘度初始設為一個很大的數
        for(int i = 0; i < N; i++){
            int maxComponent = 0;
            // 檢查以 i 為根的各個子樹
            for(auto next : tree[i]){
                if(next == parent[i]) continue; // 忽略父節點方向
                maxComponent = max(maxComponent, subtree[next]);
            }
            // 檢查拔除 i 後，剩餘部分（父節點那邊）的節點數
            int rest = N - subtree[i];
            maxComponent = max(maxComponent, rest);
            // 更新最小慘度及對應的節點編號
            if(maxComponent < best){
                best = maxComponent;
                centroid = i;
            } else if(maxComponent == best && i < centroid){
                centroid = i;
            }
        }
        
        cout << centroid << "\n";
    }
    return 0;
}
