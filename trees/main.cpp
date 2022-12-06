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

node* searchBST(node* root, int key){
    if (root == NULL){
        return NULL;
    }

    if (key == root->data){
        return root;
    }
    if (key < root->data){
        return searchBST(root->left_child, key);
    }
    if (key > root->data){
        return searchBST(root->right_child, key);
    }
}

node* inordersucc(node* root){
    node* curr = root;
    while(curr && curr->left_child != NULL){
        curr = curr->left_child;
    }
    return curr;
}

node* deletion(node* root, int key){
    if (key < root->data){
        root->left_child = deletion(root->left_child, key);
    }

    else if (key > root->data){
        root->right_child = deletion(root->right_child, key);
    }

    else{
        if (root->left_child == NULL){
            node* temp = root->right_child;
            free(root);
            return temp;
        }

        else if (root->right_child == NULL){
            node* temp = root->left_child;
            free(root);
            return temp;
        }

        else{
            node* temp = inordersucc(root->right_child);
            root->data = temp->data;
            root->right_child = deletion(root->right_child, temp->data);
        }
    }
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

    cout << "before deletion:"<< endl;
    inorder(root);
    deletion(root,1);
    cout << endl << "after deletion:" << endl;
    inorder(root);
    
    return 0;
}