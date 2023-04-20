#include <bits/stdc++.h>

using namespace std;
vector<int> v(100005);
struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

    node * root;
    node * add(node * current, int val){
        if(current == NULL){
            current = new node(val);
        }else if(current->val > val){
            if(current->left == NULL){
                current->left = add(current->left, val);
            }else{
                add(current->left, val);
            }
        }else if(current->val < val){
            if(current->right == NULL){
                current->right = add(current->right, val);
            }else{
                add(current->right, val);
            }
        }
        return current;
    }
    void print(node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

    void findof(node*curr ){
        if(curr == NULL) return;
        int cnt = 0;
        node*left = curr ->left;
        node*right = curr -> right;
        while(left and right){
            v[cnt]++;
            cnt++;
            left = left -> left;
            right = right -> right;
        }
        findof(curr ->left);
        findof(curr -> right);
    }

    void print2(int n){
        for(int i=0; i<n - 1; i++){
            cout << v[i] << " ";
        }
    }


int main(){
    int n; cin>>n;
    for (int i=0; i<n; i++){
        int mem; cin>>mem;
        root = add(root, mem);
    }
    
    findof(root);
    print2(n);

}