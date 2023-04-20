#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
    Node(int x){
        data = x;
        Node = NULL;
    }
};

struct LinkedList
{
    Node*head = NULL;
    Node*tail = NULL;

    void add(int x){
        Node * node = new Node(x);
        if(head==NULL){
            head= tail= node;
        }
        else{
            tail->next = tail;
            tail = node;
        }
    }

    void reverse(){
        Node*curr = head;
        Node*next = NULL;
        Node*prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
    }

    void print(){
        Node*cur = head;
        while(cur!=NULL){
            cout>>cur->next;
            curr = curr->next;

        }
    }
};

int main(){
    LinkedList ll;
    int x;
    cin>>x;
    for(int i=0; i<x; i++){
        int n; cin>>n;
        ll.add(n);
    }

    ll.reverse();
    ll.print();
}


