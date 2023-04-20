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
    int cnt = 0;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    Node * change(Node * cur){
        if(cur != nullptr){
            change(cur -> right);
            cur -> val += cnt;
            cnt = cur -> val;
            change(cur -> left);
        }
    }

    Node * inOrder(Node * cur){
        if(cur != nullptr){
            inOrder(cur -> right);
            cout << cur -> val << " ";
            inOrder(cur -> left);
        }
    }

public:
    bst(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void change(){
        change(root);
    }

    void inOrder(){
        inOrder(root);
    }

};

int main(){
    bst b;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push(x);
    }
    b.change();
    b.inOrder();
}