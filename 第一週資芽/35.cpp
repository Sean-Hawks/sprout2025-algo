#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    stack<int> sta;
    cin >> t;
    
    while(t > 0){
        int check, n;
        cin >> check;
        
        if(check == 1){
            cin >> n;
            sta.push(n);
        }else if(check == 2){
            if(!sta.empty()){
                cout << sta.top() << endl;
                sta.pop();
            }else if(sta.empty()){
                cout << "empty!\n";
            }
        }
        t--;
    }
    return 0;
}