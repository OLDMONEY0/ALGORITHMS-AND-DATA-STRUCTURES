#include <iostream>

using namespace std;

int maximum = 1;

struct Node
{
    Node* prev;
    Node* next;
    int data;
    int cnt;
    Node(int _data){
        prev = NULL;
        next = NULL;
        data = _data;
        cnt = 1;
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
        Node * cur = head;
        while(cur != NULL){
            if(cur->data == x){
                cur->cnt++;
                if(cur->cnt > maximum)maximum = cur->cnt;
                break;
            }
            if(cur -> next == NULL){
                cur -> next = newNode;
                break;
            }
            cur = cur->next;
        }
    }
}

void sort(){
    Node *i = head;
    Node *j = head->next;
    while(i != NULL){
        while(j != NULL){
            if(i->data < j->data){
                swap(i->data, j->data);
                swap(i->cnt, j->cnt);
            }
            j = j->next;
        }
        i = i->next;
        j = i;
    }
}

void print(){
    Node* cur = head;
    while(cur != NULL){
        if(maximum == cur->cnt)cout << cur->data << " ";
        cur = cur ->next;
    }
}


int main()
{
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        push_back(x);
    }
    print();
}