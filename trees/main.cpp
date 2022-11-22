#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *left_child;
    node *right_child;

    node(int val){
        data=val;
        left_child = NULL;
        right_child = NULL;
    }
};

void preorder(node *root){
    if (root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left_child);
    preorder(root -> right_child);
};

void inorder(node *root){
    if (root == NULL){
        return;
    }
    inorder(root -> left_child);
    cout << root -> data << " ";
    inorder(root -> right_child);
}

void postorder(node *root){
    if (root == NULL){
        return;
    }
    postorder(root ->left_child);
    postorder(root -> right_child);
    cout << root -> data << " ";
}

int main(){
    node* root = new node(1);
    root -> left_child = new node(2);
    root -> right_child = new node(3);
    root -> left_child -> left_child = new node(4);
    root -> left_child -> right_child = new node(5);
    root -> right_child -> left_child = new node(6);
    root -> right_child -> right_child = new node(7);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}
