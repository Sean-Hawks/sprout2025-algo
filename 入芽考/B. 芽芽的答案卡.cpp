#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main(){
    int n; int m; int k; int cnt = 1; int temp = 0;
    cin >> n >> m >> k;
    vector<int> arr(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(k*m<n){ cout << -1; return 0;}

    for(int i = 0; i < n; i++){
        if(arr[i] > temp){
            ans[i] = cnt;

        }else if(arr[i] <= temp){
            cnt++;
            ans[i] = cnt;
        }
        temp = arr[i];
    }
    if(cnt > k){ cout << -1; return 0;} 
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}




    
    // for(int i = 0; i < n; i++){
    //     // cout << i << " ";
    //     if(k > n - i){
    //         // cout << k << " >= " << n - i;
    //         ans[i] = cnt;
    //         cnt += 1;
    //         k -= 1;
    //     }else if(k <= n - i){
    //         if(arr[i] > temp){
    //             // cout << arr[i] << " > " << temp << endl;
    //             ans[i] = cnt;
    //             temp = arr[i];
    //         }else if(arr[i] <= temp){
    //             // cout << arr[i] << " <= " << temp << endl;
    //             k--;
    //             cnt++;
    //             ans[i] = cnt;
    //         }
    //     }
    //     if(k <= 0){ cout << -1; return 0;}

    // }
    // cout << endl;


/*
5 100 4
40 80 70 60 30
1  1  2  3  4  

5 100 3
40 80 70 60 30
1  1  1  2  3  wrong
1  1  2  3   
-1
*/