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

    int maxDistance(Node * cur){
        if(cur == nullptr) return 0;
        int lheight = height(cur -> left);
        int rheight = height(cur -> right);
        int ldis = maxDistance(cur -> left);
        int rdis = maxDistance(cur -> right);

        return max(lheight + rheight + 1, max(ldis, rdis));
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

    int maxDistance(){
        return maxDistance(root);
    }

};

int main(){
    bst b;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push(x);
    }
    cout << b.maxDistance();
}