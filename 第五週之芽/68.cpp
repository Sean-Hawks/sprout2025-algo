#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(int i = 0; i < n; i++){
            long long value;
            cin >> value;
            minHeap.push(value);
        }
        
        long long cost = 0;
        while(minHeap.size() != 1){
            long long num1 = minHeap.top();
            minHeap.pop();
            long long num2 = minHeap.top();
            minHeap.pop();
            cost += num1 + num2;
            minHeap.push(num1 + num2);
        }
        cout << cost << endl;
            
    }
        
    
}    
