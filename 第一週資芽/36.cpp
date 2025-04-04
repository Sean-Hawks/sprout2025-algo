#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    queue<int> que;
    cin >> t;
    
    while(t > 0){
        int check, n;
        cin >> check;
        
        if(check == 1){
            cin >> n;
            que.push(n);
        }else if(check == 2){
            if(!que.empty()){
                cout << que.front() << endl;
                que.pop();
            }else if(que.empty()){
                cout << "empty!\n";
            }
        }
        t--;
    }
    return 0;
}