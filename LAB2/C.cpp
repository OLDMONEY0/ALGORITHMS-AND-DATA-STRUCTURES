#include <iostream>

using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList()
{
    Node*head;
    Node*tail;
    int size;

    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push_front(int x){
        size++;
        Node*newNode = new Node(x);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void printodd(int n){
        Node *current = tail;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 and i != 1){
                cout << current -> data << " ";
            }
            current = current -> prev;
        }

    }
};

int main()
{
    LinkedList linkl;
    int n; cin >> n;
    for(int i = 0 ; i  < n ; i++){
        int x; cin >> x;
        linkl.push_front(x);
    }
    linkl.printodd(n);