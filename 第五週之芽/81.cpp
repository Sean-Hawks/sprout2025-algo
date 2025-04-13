#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

struct person{
    int start_time;
    int cook_time;
    int needed_time;
    int finish_time;
    int total_cook;
};

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<person> order(n);
    
        for(int i = 0; i < n; i++){
            cin >> order[i].cook_time >> order[i].needed_time;             
        }
        sort(order.begin(), order.end(), [](const person &a, const person &b) {
            return a.needed_time > b.needed_time;
        }); // sort order.needed_time
        
        int max = 0;
        for(int i = 0; i < n; i++){
            order[i].total_cook = order[i].cook_time + order[i-1].total_cook;
            //if(i == 0){ 
            //    order[i].finish_time = order[i].total_time + order[i].needed_time; 
            //}else{(i = 0){
            order[i].finish_time = order[i].total_cook + order[i].needed_time;
            //}
            // cout << order[i].finish_time << endl;
            if(order[i].finish_time > max)
                max = order[i].finish_time;
        }
        
        cout << max << "\n";
    }
}
/*
1
3
1 1 // 3 + 2 + 1 + 1
2 2 // 他的結束的時間應該是 3 + 2 + 2
3 3 // 3 + 3
*/

