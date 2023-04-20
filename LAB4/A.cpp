#include <iostream>

using namespace std;

string s;

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

    void move(string s){
        this->move(this->root, s);
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

    void move(node * current, string s){
        bool ok = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R'){
                current = current->right;
            }
            else current = current->left;

            if(current == NULL){
                cout << "NO\n";
                ok = true;
                break;
            }
        }

        if(!ok)cout << "YES\n";
    }
};


int main(){
    bst * b = new bst();
    int n, m; cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        b->add(x);
    }
    string arr[m];
    for(int i = 0; i < m; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < m; i++){
        b->move(arr[i]);
    }
}