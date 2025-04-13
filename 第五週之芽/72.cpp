#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        vector<int> castle(0);
        cin >> n;
        bool judge = 0; // judging the next value is taller
        
        int value = 0; // set the first value
        cin >> value;
        castle.push_back(value); 
        judge = 1; // next value will be lower

        for(int i = 1; i < n; i++){
            cin >> value;
            int last = castle.back();
            if(judge == 0){ 
                if(value > last){ // if the value is taller than than last value
                    castle.push_back(value); 
                    judge = 1;   
                }else if(value < last){
                    castle.back() = value;
                }
            }else{    
                if(value < last){
                    castle.push_back(value);
                    judge = 0;
                }else if(value > last){
                    castle.back() = value;
                }
            } 
        }
        // for(int i = 0; i < castle.size(); i++){
        //     cout << castle[i] << " ";
        // }
        if(castle.size() % 2 == 1){
            cout << castle.size() << "\n";
        }else{
            cout << castle.size() - 1 << "\n";
        }
     }
}
