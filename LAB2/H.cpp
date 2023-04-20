#include <iostream>

using namespace std;

int count = 0;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this -> val = val;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;

    void insert(int val,int pos){
        Node* NewNode = new Node(val);
        int cnt = 0;
        if(head == NULL){
            head = tail = NewNode;
            count++;
            return;
        }
        else if(pos == count){
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
            count++;
            return;
        }
        else if(pos == 0){
            NewNode -> next = head;
            head -> prev = NewNode;
            head = NewNode;
            count++;
            return;
        }
        Node* cur = head;
        while(cnt != pos){
            cur = cur -> next;
            cnt++;
        }
        NewNode -> prev = cur -> prev;
        NewNode -> next = cur;
        cur -> prev = NewNode;
        cur -> prev -> prev -> next = NewNode;
        count++;
    }

    void remove(int pos){
        int cnt = 0;
        if(pos == 0){
            head = head -> next;
            head -> prev = NULL;
            count--;
            return;
        }
        Node* cur = head;
        if(pos == count - 1){
            tail -> prev -> next = NULL;
            tail = tail -> prev;
            count--;
            return;
        }
        while(cnt != pos){
            cur = cur -> next;
            cnt++;
        }
        cur -> next -> prev = cur -> prev;
        cur -> prev -> next = cur -> next;
        cur = NULL;
        count--;
    }

    void swap(int pos1, int pos2){
        Node* cur = head;
        int cnt = 0;
        while(cnt != pos1){
            cur = cur -> next;
            cnt++;
        }
        int c = cur -> val;
        remove(pos1);
        insert(c,pos2);
    }

    void reverse(){
        Node* cur = head;
        Node* next = NULL;
        Node* prev = NULL;
        tail = cur;
        while(cur){
            next = cur -> next;
            cur -> prev = next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void cyclic_left(int k){
        int cnt=0;
        Node* cur = head;
        while(cur){
            if(cnt == k%count){
                head = cur;
                return;
            }
            else{
                Node* newNode = new Node(cur->val);
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = tail -> next;
                head = head -> next;
                head -> prev = NULL;
            }
            cur = cur -> next;
            cnt++;
        }
    }
    void cyclic_right(int k){
        int cnt = 0;
        Node* cur = tail;
        while(cur){
            if(cnt == k % count){
                tail = cur;
                return;
            }
            else{
                Node * newNode = new Node(cur -> val);
                head -> prev = newNode;
                newNode -> next = head;
                head = newNode;
                tail = tail -> prev;
                tail -> next = NULL;
            }
            cur = cur -> prev;
            cnt++;
        }
    }

    void print(){
        Node * cur = head;
        if(cur == NULL){
            cout << -1 << endl;
            return;
        }
        while(cur != NULL){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList ll;
    while (true)
    {
        int command; cin >> command;
        if (command == 0)break;
        else if(command == 1){
            int x, p; cin >> x >> p;
            ll.insert(x,p);
        }else if (command == 2){
            int p; cin >> p;
            ll.remove(p);
        }else if (command == 3){
            ll.print();
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            ll.swap(p1, p2);
        }else if (command == 5){
            ll.reverse();
        }else if (command == 6){
            int x; cin >> x;
            ll.cyclic_left(x);
        }else if (command == 7){
            int x; cin >> x;
            ll.cyclic_right(x);
        }   
    }
    return 0;
}