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

bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAthead(node* &head){
    node* todelete = head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int val){

    // Corner Cases
    // 1    No element in a list
    if(head == NULL){
        return;
    }
    // 2    Only one element in a list
    if(head->next == NULL){
        deleteAthead(head);
        return;
    } 

    node* temp = head;
    // To find node just before the val's node
    // We actually iterate from 2nd element   So deletion at head not possible
    while(temp->next->data != val){
        temp = temp->next;
    }
    // Selecting the nth node i.e, val's node
    node* todelete = temp->next;
    // To change the n-1'th node to n+1th node where nth node is of val
    temp->next = temp->next->next;

    delete todelete;    // Deletion is  a must to prevent memory leak
}

// void deletion(node* &head,int key){
//         if(head == NULL){
//         return;
//     }
//     // 2    Only one element in a list
//     if(head->next == NULL){
//         deleteAthead(head);
//         return;
//     } 


//     node* temp = head;
//     while(temp->next!=NULL){
//         if(temp->next->data==key){
//             temp->next=temp->next->next;
//             return;
//         }
//     }
// }

int32_t main(){

    node* head = NULL;

    // Appending
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,5);

    // Print 
    display(head);

    // inserting
    insertAthead(head,4);

    // Searching
    cout << search(head,4) << endl;

    // Deletion any element in an Linked List except 1st node
    deletion(head,3);
    display(head);

    // Delete at head
    deleteAthead(head);
    display(head);  

    return 0;
}