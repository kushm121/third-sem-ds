#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;

    }
};

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverse(node* &head){
    node* curr = head;
    node* next = NULL;
    node* prev = NULL;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(){

    node* head =NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    display(head);

    cout << endl << "after reversing:" << endl;
    reverse(head);
    display(head);
    return 0;
}
