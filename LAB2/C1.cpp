#include <iostream>

using namespace std;

struct Node{
    int data;
    Node*Next;
    Node*Prev;
    Node(int _data){
        data = _data;
        Next = NULL;
        Prev = NULL;
    }
};

struct LinkedList{
    Node*head;
    Node*tail;
    int size;

    LinkedList(){
        head=NULL;
        tail = NULL;
        size = 0;
    }

    void push_prev(int x){
        size++;
        Node*node = new Node(x);
        if (head == NULL){
            head=tail=node;
        }
        else{
            head->Prev=node;
            node->Next=head;
            head = node;
        }
        
    }

    void check(int n){
        Node*curr=tail;
        for(int i=0; i<n; i++){
            if(i%2 == 0 and i!=1){
                cout << curr->data<<" ";
            }
            curr=curr->Prev;
        }

    }
};

int main(){
    LinkedList ll;
    int n;
    cin>>n;
    for (int i = 0 ; i  < n ; i++){
        int x;
        cin>>x;
        ll.push_prev(x);
    }
    ll.check(n);
}