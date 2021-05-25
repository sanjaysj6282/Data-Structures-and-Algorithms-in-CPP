// Circular linked List
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
    
        node(int val){
            data = val;
            next=NULL;
        }
};

void insertatHead(node* &head,int val){
    node* n= new node(val);

    if(head==NULL){
        n->next=n;
        head = n;
        return;
    }

    node* temp = head;        
    while(temp->next!=head){  
        temp = temp->next;    
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){

    if(head == NULL){
        insertatHead(head,val);
        return;
    }

    node* n= new node(val);
    node* temp = head;        
    while(temp->next!=head){  
        temp = temp->next;    
    }
    temp->next=n;
    n->next=head;
}

void display(node* head){
    node* temp=head;
    // Do while is used to check condition after execution
    // 1st it executes then checks the condition
    // It executes once more than while
    do{
        cout << temp->data <<" ";
        temp=temp->next;
    }while(temp!=head);
    cout << "\n";
}

void deleteAtHead(node* &head){
    node* todelete = head;
    node* temp=head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next=head->next;
    head= head->next;

    delete todelete;

}

void deletion(node* &head, int pos){

    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;    // Deletion is  a must to prevent memory leak
}

int main(){

    node* head =NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertatHead(head,5);
    display(head);
    deletion(head,1);
    display(head);

    return 0;
}