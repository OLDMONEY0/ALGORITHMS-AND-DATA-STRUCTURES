#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class bst{
private:
    Node * root;
    int sum = 0;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    } 

    void levels(Node* cur, int level) {
    if (!cur) return;
    if (level == 0) sum += cur -> val;
    else {
        levels(cur -> left, level - 1);
        levels(cur -> right, level - 1);
    }
}

public:
    bst(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    int height(){
        return height(root);
    }

    void levels(){
        int h = height();
        cout << h << "\n";
        for(int i = 0; i < h; i++){
            levels(root, i);
            cout << sum << " ";
            sum = 0;
        }
    }

};

int main(){
    bst b;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push(x);
    }
    b.levels();
}