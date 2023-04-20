#include <iostream>

using namespace std;

struct Node{
	int val;
	int cnt;
	Node *left;
	Node *right;

	Node(int val){
		this->val = val;
		this->left = this->right = NULL;
		this->cnt = 0;
	}
};

class bst{
public:
	Node *root;

	bst(){
		root = NULL;
	}

	void push(int val){
        root = push(root, val);
	}

	void deleteNode(int val){
		this->deleteNode(root, val);
	}

	int getCnt(int val){
		Node* temp = find(root, val);

		if(temp == NULL)
			return 0;

		return temp->cnt;
	}

private:
	Node* push(Node* cur,int val){
		if(cur == NULL){
			cur = new Node(val);
			cur->cnt++;
		}
		else if(val < cur->val){
			if(cur->left == NULL)
				cur->left = push(cur->left, val);
			else
				push(cur->left, val);
		}
		else if(val > cur->val){
			if(cur->right == NULL)
				cur->right = push(cur->right, val);
			else
				push(cur->right, val);
		}
		else{
			cur->cnt++;
		}

		return cur;
	}

	Node* find(Node* cur, int val){
		if(cur == NULL)
			return NULL;

		if(cur->val == val)
			return cur;

		if(val < cur->val)
			cur = cur->left;
		else
			cur = cur->right;

		return find(cur, val);
	}

	Node* findMin(Node* cur){
		if(cur == NULL)
			return NULL;

		while(cur->left != NULL)
			cur = cur->left;
		return cur;
	}

	void deleteNode(Node* cur, int val){
		if(cur == NULL)
			return;

		Node* temp = find(cur, val);
		if(temp != NULL && temp->cnt > 1){
			temp->cnt--;
			return;
		}

		temp->cnt = 0;
		if(temp->left == NULL && temp->right == NULL)
			temp = NULL;
		else if(temp->left)
			temp = temp->left;
		else if(temp->right)
			temp = temp->right;
		else{
			Node* minInRightSubtree = findMin(cur->right);
			temp->val = minInRightSubtree->val;
			deleteNode(temp->right, temp->val);
		}
	}
};

int main(){
    bst b;

	int n; cin >> n;

	while(n--){
		string s;
		int x;
		cin >> s >> x;

		if(s == "insert"){
			b.push(x);
		}
		else if(s == "cnt"){
			cout << b.getCnt(x) << '\n';
		}
		else{
			b.deleteNode(x);
		}
	}
}