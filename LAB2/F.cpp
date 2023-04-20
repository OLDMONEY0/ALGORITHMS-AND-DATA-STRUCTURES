#include <iostream>

using namespace std;

struct Node{
    Node* prev;
    Node *next;
    int data;
    Node(int _data){
        prev = NULL;
        next = NULL;
        data = _data; 
    }
};

Node *head = NULL;
Node *tail = NULL;

void push_back(int x){
    Node * newNode = new Node(x);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insert(int x, int pos){
    int i = 0;
    Node * cur = tail;
    while(i != pos){
        cout << cur->data << " ";
        cur = cur->prev;
        i++;
    }
    cout << x << " ";
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur ->prev;
    }
}


int main(){
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        push_back(x);
    }
    int val, pos; cin >> val >> pos;
    insert(val, pos);
}