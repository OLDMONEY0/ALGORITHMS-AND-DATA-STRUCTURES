#include <iostream>

using namespace std;

int size = 0;

struct Node{
    Node* prev;
    Node* next;
    string data;
    Node(string _data){
        prev = NULL;
        next = NULL;
        data = _data;
    }
};

Node *head = NULL;
Node *tail = NULL;

void add_front(string s){
    Node * newNode = new Node(s);
    if(head == NULL){
        head = tail = newNode;
        size++;
    }
    else{
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
        size++; 
        /*
        1 2 3
        1: head = tail = 1;
        2: 1 -> prev = 2    2->next = 1    head = 2;
        3: 2 -> prev = 3    3->next = 2    head = 3;
        print : 3 2 1 
        */
    }
}

void add_back(string s){
    Node * newNode = new Node(s);
    if(head == NULL){
        head = tail = newNode;
        size++;
    }
    else{
        tail->next = newNode;
        newNode ->prev = tail;
        tail = newNode;
        size++;
        /*
        1 2 3
        1: head = tail = 1;
        2: 2 -> next = 1    1 -> prev = 2   tail = 2 
        3: 3 -> next = 2    2 -> prev = 3   tail = 3
        print : 1 2 3
        */
    }
}

bool empty(){
    if(size == 0)return true;
    return false;
}


string back(){
    if(size != 0)return tail->data;
    return "error";
}


string front(){
    if(size != 0)return head->data;
    return "error";
}

void erase_front(){
    if(size == 0)cout << "error\n";
    else{
        cout << front() << endl;
        if(head -> next == NULL){
            tail = head = NULL;
            size--;
        }
        else{
            head -> next -> prev = NULL;
            head = head -> next;
            size--;
        }
    }
}

void erase_back(){
    if(size == 0)cout << "error\n";
    else{
        cout << back() << endl;
        if(tail->prev == NULL){
            head = tail = NULL;
            size--;

        }
        else{
            tail-> prev-> next = NULL;
            tail = tail->prev;
            size--;
        }
    }
}


int get_size(){
    return size;
}

void clear(){
    Node* cur;
    while(head != NULL){   
        cur = head;
        head = head -> next;
    }
    size = 0;
    cout << "ok\n";

}

int main()
{
    string s; 
    while(cin >> s){
        if(s == "add_front"){
            string x; cin >> x;
            cout << "ok\n";
            add_front(x);
        }
        if(s == "add_back"){
            cout << "ok\n";
            string x; cin >> x;
            add_back(x);
        }
        if(s == "erase_front"){
            erase_front();   
        }
        if(s == "erase_back"){
            erase_back();
        }
        if(s == "front"){
            cout << front() << endl;
        }
        if(s == "back"){
            cout << back() << endl;
        }
        if(s == "clear"){
            clear();
        }
        if(s == "exit"){
            cout << "goodbye\n";
            break;
        }
    }
}