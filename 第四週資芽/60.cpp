#include <iostream>
#include <vector>
#include <string>
using namespace std;

// const int maxx;

vector<vector<int>> board; // 9x9 數獨盤，空格以 0 表示
vector<vector<bool>> row;  // row[i][d]：第 i 行是否已使用 d
vector<vector<bool>> column; // column[j][d]：第 j 列是否已使用 d
vector<vector<bool>> block; // block[k][d]：第 k 區塊是否已使用 d
vector<pair<int,int>> dot; // 記錄所有空格的位置

// 輸出 board
void output(){ 
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
        }
    }
    cout << "\n";
}

// 判斷值是否可以塞進 board
bool canPlace(int r, int c, int d){ 
    int bIdx = (r / 3) * 3 + c / 3;
    // 如果該行、該列、該區塊都未使用 d，則可以放入
    return (!row[r][d] && !column[c][d] && !block[bIdx][d]);
}

// 檢查初始盤面是否合法
bool isValidInitialBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int d = board[i][j];
            if (d != 0) { // 只檢查已填數字
                int bIdx = (i / 3) * 3 + (j / 3);
                // 若該行/列/區塊已經使用過 d，則衝突
                if (row[i][d] || column[j][d] || block[bIdx][d]) {
                    return false; // 初始盤面不合法
                }
                // 否則登記使用
                row[i][d] = column[j][d] = block[bIdx][d] = true;
            }
        }
    }
    return true; // 若無衝突則合法
}


bool dfs(int depth){ // depth 為 dot 的第幾項
    if(depth == dot.size()){ // 結束條件
        output();
        return true;
    }

    int r = dot[depth].first;
    int c = dot[depth].second;
    int bIdx = (r / 3) * 3 + c / 3; 

    // 嘗試填入 1~9
    for(int d = 1; d <= 9; d++){
        if(canPlace(r, c, d)){ // 判斷值是否可以塞進 board
            // 將取代掉的值變成 true
            board[r][c] = d;
            row[r][d] = true;
            column[c][d] = true;
            block[bIdx][d] = true;

            // 遞迴下一層
            if (dfs(depth + 1)){
                return true;
            }

            // 回溯
            board[r][c] = 0;
            row[r][d] = false;
            column[c][d] = false;
            block[bIdx][d] = false;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        string str;
        cin >> str;

        // 初始化
        board.assign(9, vector<int>(9, 0));
        row.assign(9, vector<bool>(10, false));
        column.assign(9, vector<bool>(10, false));
        block.assign(9, vector<bool>(10, false));
        dot.clear();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = str[i * 9 + j];

                // 如果是點就將此格設為 0
                if (c == '.'){
                    dot.push_back({i, j});    
                    board[i][j] = 0;       // 空格以 0 表示
                } else{
                    int num = c - '0';
                    board[i][j] = num;

                    // 將值塞入 row, column, block
                    row[i][board[i][j]] = true;
                    column[j][board[i][j]] = true;
                    block[(i/3)*3 + j/3][board[i][j]] = true;
                    

                }
            }
        }

        // 先把 row/column/block 清空後再跑一次檢查
        row.assign(9, vector<bool>(10, false));
        column.assign(9, vector<bool>(10, false));
        block.assign(9, vector<bool>(10, false));        
        
        if (!isValidInitialBoard()) {
            cout << "No solution." << "\n";
            continue; // 不合法，直接跳到下一筆測試
        }

        //dfs
        if(!dfs(0)){
            cout << "No solution." << "\n";
        }
    }
}