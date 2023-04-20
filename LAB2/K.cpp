#include <iostream>

using namespace std;

struct Node{
    pair <bool,char> pr;
    Node* next;
    Node* prev;

    Node(char val){
        pr.first = true;
        pr.second = val;
        next = nullptr;
        prev = nullptr;
    }
};

struct LinkedList{
    public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(char val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void check(){
        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->pr.second == tail->pr.second){
                temp->pr.first = false;
                tail->pr.first = false;
            }
            temp = temp->next;
        }

        temp = head;
        while(temp != nullptr){
            if(temp->pr.first == true){
                cout << temp->pr.second << " ";
                return;
            }
            temp = temp->next;
        }
        cout << -1 << " ";
    }
};

int main()
{
    LinkedList ll;
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        for(int i = 0; i < x; i++){
            char c; cin >> c;
            ll.push(c);
            ll.check();
        }
        cout << endl;
        ll.head = nullptr;
    }
}