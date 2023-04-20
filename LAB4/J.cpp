#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;

    Node(int val){
        this -> val = val;
        right = left = nullptr;
    }
};

class bst{
    private:

    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val > cur->val) cur->right = push(cur->right, val);
        if(val < cur->val) cur->left = push(cur->left, val);
        return cur;
    }

    Node * createBalancedTree(vector<int> &v, int start, int end){
        if (start > end) return nullptr;
        int mid = (start + end)/2;
        Node * root = new Node(v[mid]);
        root -> left = createBalancedTree(v, start, mid - 1);
        root -> right = createBalancedTree(v, mid + 1, end);
        return root;
    }

    Node * inOrder(Node * cur){
        if(cur != nullptr){
            cout << cur -> val << " ";
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }
   
    public:
    Node * root;

    bst(){
        root = nullptr;
    }
    
    void push(int val){
        root = push(root, val);
    }

    void inOrder(){
        inOrder(root);
    }

    Node * createBalancedTree(vector<int> &v){
        return createBalancedTree(v, 0, v.size() - 1);
    }
};

int main(){
    bst b;
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < pow(2, n) - 1; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    b.root = b.createBalancedTree(v);
    b.inOrder();
}