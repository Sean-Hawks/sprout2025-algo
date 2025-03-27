#include <iostream>
#include <vector>
using namespace std;

// 使用 DFS 遞迴計算以 u 為根的子樹大小
void dfs(int u, const vector<vector<int>>& children, vector<int>& subtree_size) {
    subtree_size[u] = 1;  // 自己也要計算在內
    for (int v : children[u]) {
        dfs(v, children, subtree_size);
        subtree_size[u] += subtree_size[v];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        // 建立鄰接串列儲存子節點
        vector<vector<int>> children(n + 1);
        // 記錄每個箱子的父節點，初始值皆為 0（代表沒有父節點，即最外層箱子）
        vector<int> parent(n + 1, 0);
        
        // 讀取 m 次操作，每次將箱子 y 放入箱子 x 中
        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            children[x].push_back(y);
            parent[y] = x;
        }
        
        // 利用 DFS 計算每個節點的子樹大小
        vector<int> subtree_size(n + 1, 0);
        // 由於最外層的箱子為根，找出所有 parent[i] == 0 的箱子作 DFS
        for (int i = 1; i <= n; i++){
            if (parent[i] == 0){
                dfs(i, children, subtree_size);
            }
        }
        
        int q;
        cin >> q;
        // 處理每個查詢，直接輸出預先計算好的子樹大小
        for (int i = 0; i < q; i++){
            int x;
            cin >> x;
            cout << subtree_size[x] << "\n";
        }
    }
    return 0;
}
