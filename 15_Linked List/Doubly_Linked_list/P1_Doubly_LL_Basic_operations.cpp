// Doubly linked List
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;
    
        node(int val){
            data = val;
            prev=NULL;
            next=NULL;
        }
};

void insertAtHead(node* &head,int val){

    node* n = new node(val);
    n->next=head;
    if(head!=NULL)
        head->prev=n;

    // If thre is no such linked list
    head=n;
}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n =new node(val);
    node* temp = head;

    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev = temp;

}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data<< " ";
        temp=temp->next;
    }
    cout << endl;
}

// Corner Case
void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* &head,int pos){
    // Corner case --> at head
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while (temp!=NULL && count != pos){
        temp=temp->next;
        count++;
    }
    // Easy
    temp->prev->next = temp->next;
    // Corner case --> at tail
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    
}

int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);

    insertAtHead(head,5);
    display(head);

    deletion(head,2);
    display(head);

    deletion(head,5);
    display(head);

    deletion(head,1);
    display(head);

    return 0;
}