#include <iostream>
#include <vector>
using namespace std;

struct Node{ 
    int data;
    Node *left, *right; // 建立往左和右子樹的指標
    Node(int val){ // 建構子 在建立 Node 的同時順便創建空指標，直接在 struct 塞函式很酷
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value){ // 新建值
    if(root == nullptr){ // 如果根節點是空指標
        return new Node(value); // 如果不寫 new 會因為是區域變數而被吃掉，用 new 重新配置記憶體
    }
    if(value < root->data){ // 如果要 insert 的值小於此節點指到的 data
        root->left = insert(root->left, value); // root->left 也就是 (*root).left，再更深一層近去 root->left    
    }
    if(value > root->data){ // 同理
        root->right = insert(root->right, value);
    }
    return root; // 用來 reset 這個 Tree 否則 root 將指向空值}
}

void postorder(Node* root){ // 後序
    if(root == nullptr){ // 終止條件 
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}

int main(){
    int N;
    cin >> N;

    Node* root = nullptr;
    
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        root = insert(root, value);
    }
    postorder(root);
    return 0;
}