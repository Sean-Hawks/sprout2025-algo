#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        // 分別讀入 1x1, 2x2, 3x3, 4x4, 5x5, 6x6 禮物的數量
        int count1, count2, count3, count4, count5, count6;
        cin >> count1 >> count2 >> count3 >> count4 >> count5 >> count6;
        
        int boxes = 0;
        
        // (1) 6x6 禮物: 每個必須獨占一個箱子
        boxes += count6;
        
        // (2) 5x5 禮物: 每個占一個箱子，箱子內剩餘可放11個1x1
        boxes += count5;
        count1 = max(0, count1 - count5 * 11);
        
        // (3) 4x4 禮物: 每個占一個箱子，箱子剩餘空間可放五個2x2
        boxes += count4;
        int spaceFor2 = count4 * 5; // 4x4箱子可以放5個2x2
        if(count2 > spaceFor2) {
            count2 -= spaceFor2;
        } else {
            int leftover = spaceFor2 - count2;   // 尚未填滿2x2的格數
            count2 = 0;
            // 每個未填滿的2x2格子可改以4個1x1補充
            count1 = max(0, count1 - leftover * 4);
        }
        
        // (4) 3x3 禮物:
        // 每箱最多可放4個3x3
        boxes += count3 / 4;
        int r = count3 % 4;
        if(r > 0){
            boxes++; // 額外不足4個的3x3需要一箱
            // 依據剩餘個數 r，不同箱子內可放 2x2 和 1x1 的數量不同
            if(r == 1){
                // 若放入1個3x3後，箱子內剩餘空間可放5個2x2和最多7個1x1
                int use = min(count2, 5);
                count2 -= use;
                count1 = max(0, count1 - (27 - use * 4)); // 27 = 36 - 9 (3x3的面積)
            } else if(r == 2){
                // 若放入2個3x3，剩餘空間可放3個2x2和6個1x1
                int use = min(count2, 3);
                count2 -= use;
                count1 = max(0, count1 - (18 - use * 4)); // 18 = 36 - 2*9
            } else if(r == 3){
                // 若放入3個3x3，剩餘空間可放1個2x2和5個1x1
                int use = min(count2, 1);
                count2 -= use;
                count1 = max(0, count1 - (9 - use * 4)); // 9 = 36 - 3*9
            }
        }
        
        // (5) 2x2 禮物:
        // 每箱最多可放9個2x2
        boxes += count2 / 9;
        if(count2 % 9){
            boxes++; // 不足9個的2x2需要一箱
            // 箱子剩餘空間 (36 - 2x2面積) 可放1x1禮物：
            count1 = max(0, count1 - (36 - (count2 % 9) * 4));
        }
        
        // (6) 1x1 禮物:
        // 每箱可放36個1x1
        boxes += (count1 + 35) / 36; // 天花板除法
        
        cout << boxes << "\n";
    }
    
    return 0;
}
// chatgpt