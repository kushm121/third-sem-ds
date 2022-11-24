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

node* insertBST (node* root, int val){
    if (root == NULL){
        return new node(val);
    }

    if (val < root -> data){
        root ->  left_child = insertBST(root -> left_child, val);
    }

    else{
        //val > root -> dat
        root -> right_child = insertBST(root -> right_child,val);
    }
    return root;
}

void inorder(node *root){
    if (root == NULL){
        return;
    }
    inorder(root -> left_child);
    cout << root -> data << " ";
    inorder(root -> right_child);
}


int main(){
    node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,6);

    inorder(root);
    cout << endl;


    return 0;
}
