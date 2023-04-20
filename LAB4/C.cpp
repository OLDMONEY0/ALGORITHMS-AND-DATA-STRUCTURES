#include <iostream>
#include <stack>

using namespace std;

int cnt = 0;

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
    
    void countsubtree(int k){
        this->countsubtree(this->root, k);
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

    node * countsubtree(node * current, int k){
        if(current != NULL){
            countsubtree(current->left, k);
            if(k == current -> val){
                print(current);
            }
            countsubtree(current->right, k);
        }
    }

    void print(node * current){
        if(current != NULL){
            cout << current->val << " ";
            print(current->left);
            print(current->right);
        }
    }


};


int main(){
    bst * b = new bst();
    int n; cin >> n;
    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        b->add(x);
    }
    int k; cin >> k;
    b->countsubtree(k);  
}