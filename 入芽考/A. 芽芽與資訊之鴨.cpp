#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool check(vector<int> arr, int i){
    if(i < 0 or i >= arr.size()){
        return 0;
    }else{
        return 1;
    }
}
int product(vector<int> arr, int a, int b){
    int pro = 1;
    if(check(arr, a) == 1){
        if(arr[a] == 1)
            pro *= 2;
    }if (check(arr, b) == 1){
        if(arr[b] == 1) 
            pro *= 2;
    }

    return pro;
}

int main(){
    int n = 0;
    int q = 0;
    cin >> n >> q;
    vector<int> duck;
    vector<int> big;
    int temp = 0;
    int pick[q];
    for(int i = 0; i < n; i++){
        cin >> temp;
        duck.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        big.push_back(temp);
    }
    for(int i = 0; i < q; i++){
        cin >> pick[i];
    }

    int total = 0;
    for(int i = 0; i < q; i++){
        temp = pick[i];
        
        total = 0;
        temp -= 1;
        
        if(check(duck, temp) == 1){
            total = total + duck[temp] * product(big, temp-1, temp+1);
        }if(check(duck, temp-1) == 1){
            total = total + duck[temp-1] * product(big, temp-2, temp);
        }if(check(duck, temp+1) == 1){
            total = total + duck[temp+1] * product(big, temp, temp+2);
        }
        
        cout << total << endl;
    }



/*
5 5
1 2 3 4 5
0 0 0 0 0
1
2
3
4
5
*/
}

// int index = 0;
//     while(index < q){
//         int temp = 0;
//         int total = 0;
//         cin >> temp;
        
//         if(temp )
//         if(big[temp-1] == 1 and big[temp+1] == 1){
//             total = duck[temp] * pow(2, 2);
//         }else if(big[temp-1] == 1 or big[temp+1] == 1){
//             total = duck[temp] * pow(2, 1);
//         }else{
//             total = duck[temp];
//         }
//         if(big[temp-2] == 1 and big[temp] == 1){
//             total = duck[temp-1] * pow(2, 2);
//         }else if(big[temp-1] == 1 or big[temp+1] == 1){
//             total = duck[temp-1] * pow(2, 1);
//         }else{
//             total = duck[temp-1];
//         }
//         index++;
//     }
