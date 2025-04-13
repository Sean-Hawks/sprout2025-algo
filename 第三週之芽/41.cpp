#include <iostream>
#include <vector>
#include <string>
using namespace std;

int H, W;
vector<string> grid;
vector<vector<bool>> visited;

// DFS 遞迴函式，從 (i, j) 開始標記連通的水池
void dfs(int i, int j) {
    if(i < 0 || i >= H || j < 0 || j >= W) return;
    // 若不是水池或已拜訪，直接返回
    if(grid[i][j] != '.' || visited[i][j]) return;
    
    visited[i][j] = true;  // 標記為已拜訪
    
    dfs(i - 1, j); // 上
    dfs(i + 1, j); // 下
    dfs(i, j - 1); // 左
    dfs(i, j + 1); // 右
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T; 
    
    while(T--) {
        cin >> H >> W;
        grid.assign(H, "");
        visited.assign(H, vector<bool>(W, false));
        
        for (int i = 0; i < H; i++){
            cin >> grid[i];
        }
        
        int count = 0;
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                // 若遇到未拜訪的水池格子，則進行 DFS 並計數
                if(grid[i][j] == '.' && !visited[i][j]){
                    dfs(i, j);
                    count++;
                }
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
//抄來的