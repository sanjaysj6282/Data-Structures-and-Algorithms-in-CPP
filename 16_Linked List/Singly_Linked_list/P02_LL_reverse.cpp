// Very Confusing
// Pictorise

// VVIMP
// Prerequsites : OOPs,Pointers (Strong)
// Interview 
// Base for Binary trees
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        // * is used to create pointer
        node* next;

        // Parameterised Constructor
        node(int val){
            data = val;
            next = NULL;
        }
};

// Head by reference , Since we are changing it  
// Note -> by passing in reference,can make its value change globally
/*
If I passed head not by reference then head value changes inside function but not outside
i.e, head remains NULL
So at display function we get NULL value 
*/
void insertAtTail(node* &head,int val){

    // To create a pointer for a new element --> (like --> temp) with [val,next]
    node* n= new node(val);
 // Corner case
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

// Imp
// head is taken by value , Since we are not modifying it
//          OR
// We can also use it by reference
// But, Conceptually(think--?) both are same in execution
void display(node* head){
    node* temp = head;  // temp is the pointer 
    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void insertAthead(node* &head,int val){

    // To create pointer for new node containg [value,not defined]
    node* n = new node(val);
    n->next = head; // [value,head]
    head=n;
}

node* reverseIterative(node* &head){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        // Reversing
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        // No need of incrementing "nextptr" Since we are doing it at beginnig of loop
    }
    return prevptr;
}

node* reverseRecursive(node* &head){

    // Base Case
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Recursive condition
    node* newhead = reverseRecursive(head->next);

    // For 1st element 
    // For making 2nd element point to 1st element i.e, head 
    head->next->next = head;
    // For making 1st element point to NULL 
    head->next = NULL;

    return newhead;
}

// VIMP
// Famous
// O(N) --> Since we are traversing only once
node* reverseK(node* &head,int k){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;
    while(currptr != NULL && count<k){
        // Reversing 2 nodes
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if (nextptr != NULL)
        head->next = reverseK(nextptr,k);

    return prevptr;
}


int32_t main(){

    node* head = NULL;

    // Appending
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,5);

    // Reverse using iterator
    // 3 pointer approach
    node* newhead = reverseIterative(head);
    display(newhead);

    // Reverse using Recursion
    // newhead is used  Since head (changes) -->newhead
    node* nhead = reverseRecursive(newhead);
    display(nhead);

    int k = 2;
    node* newhead=reverseK(head,k);
    display(newhead);

    

    return 0;
}