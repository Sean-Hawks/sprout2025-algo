#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> heap;

    make_heap(heap.begin(), heap.end(), greater<int>());

    while(T--){
        int n = 0, temp;
        cin >> n;
        
        if(n == 1){
            cin >> temp;
            heap.push_back(temp);
            push_heap(heap.begin(), heap.end(), greater<int>());
        }else{
            if(heap.empty())
                cout << "empty!" << endl;
            else{
                pop_heap(heap.begin(), heap.end(), greater<int>());
                cout << heap.back() << endl;
                heap.pop_back();
            }
        }
    }
    return 0;
}
