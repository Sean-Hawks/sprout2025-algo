#include <bits/stdc++.h>
using namespace std;

const int MAXLV = 6;
stack<int> stk;

void output(stack<int> stk){
    vector<int> temp;
    while(!stk.empty()){
        temp.push_back(stk.top());
        stk.pop();
    }
    reverse(temp.begin(), temp.end()); // 讓輸出順序是從底到頂
    for(int x : temp){
        cout << x << " ";
    }
    cout << "\n";
}

void dfs(vector<int> tree, int depth, int pointer){
    if(depth == MAXLV){
        output(stk);
        return;
    }else{
        for(int i = pointer+1; i < tree.size(); i++){
            stk.push(tree[i]);
            dfs(tree, depth+1, i);
            stk.pop();
        }
    }
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> tree(n);
        for(int i = 0; i < n; i++){
            cin >> tree[i];
        }
        
        dfs(tree, 0, -1);
    
    }
}