#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int times; int Line = 1;
    cin >> times;
    
    while(times > 0){
        unordered_map<int, unordered_set<int>> groups;
        deque<int> myQue; // 排隊隊伍
        int n;
        cin >> n;

        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            for (int j = 0; j < k; j++){
                int temp;
                cin >> temp;
                groups[i].insert(temp);
            }   
        }
        cout << "Line #" << Line << endl;
        int m;
        cin >> m;

        while (m > 0){
            string str; 
            cin >> str;
            
            if(str == "ENQUEUE"){
                int temp = 0; int groups_pos = -1; // temp 在第幾堆
                cin >> temp;

                for(int i = 0; i < n; i++){ // 備註： n 爲幾堆
                    if(groups[i].count(temp)){ // 確認 temp 存在於 groups[i] 當中
                        groups_pos = i; 
                        break;
                    }        

                if(groups_pos == -1){
                    myQue.push_back(temp);
                    continue;
                }

                auto it = myQue.end();
                }for(int j = myQue.size() - 1; j >= 0; j--){     // 往前找 myQue 從 m 往前找有沒有同堆的
                    if(groups[groups_pos].count(myQue[j])){ // 如果 myQue[j] 和 temp 是同一個 groups
                        it = myQue.begin() + j + 1;
                        break;
                    }
                }
                myQue.insert(it, temp);
                
            }
            else if(str == "DEQUEUE"){
                cout << myQue.front() << endl;
                myQue.pop_front();
            }
            m--;
        }
        

        times--; Line++;
    }
}
/*
2
2
3 1 2 3
4 4 5 6 7
12
ENQUEUE 1
ENQUEUE 4
ENQUEUE 3
ENQUEUE 2
ENQUEUE 8
ENQUEUE 6
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
2
3 10000 20000 30000
4 400000 500000 600000 700000
12
ENQUEUE 10000
ENQUEUE 400000
ENQUEUE 30000
DEQUEUE
DEQUEUE
ENQUEUE 700000
ENQUEUE 600000
ENQUEUE 500000
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
*/