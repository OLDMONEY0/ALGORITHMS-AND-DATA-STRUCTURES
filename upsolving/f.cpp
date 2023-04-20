#include <bits/stdc++.h>

using namespace std;
int sum = 0;
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

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }

    void findlevel(int level){
        this->findlevel(this->root, level);
    }

    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
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

    int findlevel(node * curr, int level){
        if(curr == NULL) return level;
        else{
            sum+=curr->val - level;
        }

        int l = findlevel(curr->left, level+1);
        int r = findlevel(curr->right, level+1);
        return sum;
    }
};

int main(){
    int n; cin>>n;
    bst * b = new bst();
    for (int i=0; i<n; i++){
        int mem; cin>>mem;
        b->add(mem);
    }

    b->findlevel(0);
    cout<<sum;

}