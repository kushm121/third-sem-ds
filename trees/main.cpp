#include <iostream>
#include <bits/stdc++.h>
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

void levelorder(node *root){
    if (root == NULL){
        return;
    }
    queue <node*> q;
    q.push(root);

    while (q.empty() == false){
        node* n = q.front();
        cout << n->data << " ";
        q.pop();

        if (n->left_child != NULL){
            q.push(n->left_child);
        }

        if (n->right_child != NULL){
            q.push(n->right_child);
        }
    }

}


int main(){
    node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,6);

    levelorder(root);
    cout << endl;


    return 0;
}