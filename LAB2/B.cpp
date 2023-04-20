#include <iostream>

using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    string data;
    Node(string _data){
        prev = NULL;
        next = NULL;
        data = _data;
    }
};

Node * head = NULL;
Node * tail = NULL;

void push_back(string s){
    Node *newNode = new Node(s);
    if(head == NULL){
         head = tail = newNode;
    }
    else{
        head->prev = newNode;
        newNode ->next = head;
        head = newNode;
    }
}
void shift(int t){
    Node *cur = tail;
    int i = 0;
    while (i != t)
    {
        i++;
        cur = cur->prev; 
    }

    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cur = tail, i = 0;
    while(i != t){
        i++;
        cout << cur->data << " ";
        cur = cur->prev;
    }
}



int main()
{
    int n,t; cin >> n >> t;
    string arr[n];
    for(int i = 0; i < n ;i++){
        string s; cin >> s;
        push_back(s);
    }
    shift(t);
}
