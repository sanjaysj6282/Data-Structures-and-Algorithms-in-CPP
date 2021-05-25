#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        // Parameterised Constructor
        node(int val){
            data = val;
            next = NULL;
        }
};

void insertAtTail(node* &head,int val){

    // To create a pointer for a new element --> (like --> temp) with [val,next]
    node* n= new node(val);

    // If there is no node yet in Linked List 
    if(head == NULL){
        head = n;
        return;
    }

    // Address = temp     eg    20000
    // [val/data , next]     [adfsm,3000]

    node* temp = head;        // temp is a pointer which points to the head
    while(temp->next!=NULL){  // the temp'th element pointer(i.e, next) != NULL
        temp = temp->next;    // To move the pointer "temp" to pointer "next"
    }
    temp->next=n;
}

void display(node* head){
    node* temp = head;  // temp is the pointer 
    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}



void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startnode;

    int count = 1;
    while (temp->next != NULL){
        if (count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;        
    }
    temp->next = startnode;

}

// For proof look video
// VVIMP
// Easy
// Interview question
// Detection and removal of cycle in Linked list
// "Floyd's" or "Hare and tortoise" algorithm
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    // fast->next is put in while loop Since fast->next->next otherwise will result in NULL
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        // To move fast 2 steps
        fast=fast->next->next;

        if(fast==slow)
            return true;
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);
    
    fast = head;
    while (slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next=NULL;
}

int32_t main(){

    node* head = NULL;

    // Appending
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    display(head);

    makeCycle(head,3);
    // Results in an Infinite loop --> hence prints infinitely
    // display(head);
    cout << detectCycle(head) << endl;
    removeCycle(head);   
    cout << detectCycle(head) << endl;
    display(head);
}