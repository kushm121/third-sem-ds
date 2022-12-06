#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data = 0) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Stack {
private:
    Node *arr[20];
    int top;
    int size;
public:
    Stack() {
        top = -1;
        size = 10;
    }

    void push(Node *root) {
        if (isFull()) {
            return;
        }
        arr[++top] = root;
        return;
    }

    Node *pop() {
        if (isEmpty()) {
            return NULL;
        }
        return arr[top--];
    }

    Node *peek() {
        if (isEmpty()) {
            return NULL;
        }
        return arr[top];
    }

    bool isFull() {
        if (top == size - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }
};

void preorder(Node* root){
    if (root == NULL){
        return;
    }
    Node* curr = root;
    Stack s;
    s.push(curr);
    for(;;){
        curr = s.pop();
        if (curr == NULL){
            break;
        }
        cout << curr->data<<" ";
        if (curr->right != NULL){
            s.push(curr->right);
        }
        if (curr->left != NULL){
            s.push(curr->left);
        }
    }
}

void inorder(Node* root){
    if (root == NULL){
        return;
    }
    Node* curr = root;
    Stack s;
    while (curr != NULL || !s.isEmpty()){
        while (curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.pop();
        if (curr == NULL){
            return;
        }
        cout << curr->data << " ";
        curr = curr->right;
    }

}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr=root;
    Node* prev=NULL;
    Stack S;
    while(curr!=NULL ||!S.isEmpty()) {
        while(curr != NULL) {
            S.push(curr);
            curr = curr->left;
        }
        prev=S.peek()->right;
        if(prev==NULL){
            prev=S.pop();
            cout<<prev->data<<" ";
            while(!S.isEmpty() and prev == S.peek()->right) {
                prev = S.peek();
                S.pop();
                cout<<prev->data<<" ";
            }
        }
        else{
            curr=prev;
        }
    }
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    cout << endl << "preorder: " << endl;
    preorder(root);

    cout << endl << "inorder: " << endl;
    inorder(root);

    cout << endl << "postorder: " << endl;
    postorder(root);
}
