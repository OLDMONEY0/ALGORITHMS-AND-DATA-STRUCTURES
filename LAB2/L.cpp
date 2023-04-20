#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *prev;
    Node *next;
    int data;
    Node(int _data){
        prev = NULL;
        next= NULL;
        data = _data;
    }
};

Node *head = NULL;
Node *tail = NULL;

void push_back(int x){
    Node *newNode = new Node(x);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    /*
    1 2 3
    1 : head = 1
    2 : 
    print: 1 2 3
    */
}

void ragnarok(int n){
    int sum = 0 , maximum = -999999;
    Node *i = head;
    while(i){
        sum += i->data;
        sum = max(sum, i->data);
        maximum = max(sum, maximum);
        i = i->next;
    }
    cout << maximum;

}

int main()
{
    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        push_back(x);
    }
    ragnarok(n);
}

