#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node(int val)
    {
        this -> val = val;
        left = right = nullptr;
    }
};

class bst
{
private:
    Node * root;
    int cnt = 0;
    Node * push(Node * cur, int val)
    {
        if(cur == nullptr) return new Node(val);
        if(val < cur -> val) cur -> left = push(cur-> left,val);
        if(val > cur -> val) cur -> right = push(cur -> right,val);
        return cur;
    }
    Node * triangles(Node * cur)
    {
        if(cur != nullptr)
        {
            if(cur -> left && cur -> right) cnt++;
            triangles(cur->left);
            triangles(cur -> right);
        }
    }
public:
    bst()
    {
        root = nullptr;
    }
    void push(int val)
    {
        root = push(root,val);
    }
    int triangles()
    {
        triangles(root);
        return cnt;
    }
};

int main()
{
    bst b;
    int n; cin >> n;
    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        b.push(x);
    }

    cout << b.triangles();
}