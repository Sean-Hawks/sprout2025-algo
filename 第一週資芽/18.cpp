#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n; int times;
    cin >> times;

    while(times > 0){
        cin >> n;
        queue<int> que;
        stack<int> sta;
        queue<int> output;

        for(int i = 1; i <= n; i++){
            int temp;
            cin >> temp;
            output.push(temp);
        }
        for(int i = 1; i <= n; i++){
            que.push(i);
        }

        while(!output.empty()){ 
            // Push 進 stack 直到 output.front() 出現在 stack 頂端
            while(!que.empty() && (sta.empty() || output.front() != sta.top())){
                sta.push(que.front());
                que.pop();
            }

            // 如果 stack 頂端的數字不是 output.front() => cout "no"
            if(sta.top() != output.front()){
                cout << "No \n";
                break;
            }

            // success => pop stack & output
            sta.pop();
            output.pop();
        }
        if(output.empty()){
            cout << "Yes \n";
        }
        times--;
    }
}
