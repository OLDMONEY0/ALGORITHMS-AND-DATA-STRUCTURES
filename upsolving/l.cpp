#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = this->right = NULL;
    } 
};


Node* root = NULL;

Node* getMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* add(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    } 
    else if (root->val > val) {
        if (root->left == NULL) {
            root->left = new Node(val);
        }
        else {
            root->left = add(root->left, val);
        }
    } else if (root->val < val) {
          if (root->right == NULL) {
              root->right = new Node(val);
            } else {
               root->right = add(root->right, val);
            }
    }
    return root;
}




int numofLeaf(Node* root){
    if(!root) return 0;
    if(!root->left && !root->right )  return 1;
    return numofLeaf(root->left) + numofLeaf(root->right);
}



int main(){
    int n; cin >> n;
    for( int i = 0; i < n; i++){
        int mem; cin>>mem;
        root = add(root,mem);
    }
    int num = numofLeaf(root);
    cout << num;
}
  


