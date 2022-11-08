#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    if (head != NULL){
        head->prev = n;
    }
    //n->prev = NULL; dpne by default because of constructor
    head = n;
}

void insertAtTail(node* &head, int val){
    if (head== NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next=n;
    n->prev=temp;
    //n->next= NULL; done by default because of constructor

}

void display(node* head){
    node* temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev=NULL;
    delete todelete;
}

void deletion(node* &head, int pos){
    if (pos == 1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count=1;
    while (temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int main(){
    node* head = NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtHead(head,1);
    display(head);
    deletion(head,4);
    deleteAtHead(head);
    display(head);

    return 0;
}
