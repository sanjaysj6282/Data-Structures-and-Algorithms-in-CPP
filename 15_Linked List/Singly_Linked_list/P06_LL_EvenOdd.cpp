#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val){
            data = val;
            next = NULL;
        }
};

void display(node* head){
    node* temp = head;  // temp is the pointer 
    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void insertAtTail(node* &head,int val){

    node* n= new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;        // temp is a pointer which points to the head
    while(temp->next!=NULL){  // the temp'th element pointer(i.e, next) != NULL
        temp = temp->next;    // To move the pointer "temp" to pointer "next"
    }
    temp->next=n;
}

void evenAfterodd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;
    while(odd->next != NULL and even->next != NULL){
        odd->next = even->next;
        odd=odd->next;
        even->next = odd->next;
        even=even->next;
    }
    odd->next = evenStart;

    // Corner Case
    // Since,we dont have EVEN pointing to any node
    if(odd->next != NULL)
        even->next = NULL;

    display(head);
}

int main(){

    node* head1 = NULL;
    node* head2 = NULL;
    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++){
        insertAtTail(head2,arr2[i]);
    }
    
    node* head = NULL;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        insertAtTail(head,arr[i]);
    }
    evenAfterodd(head);
    
    return 0;
}