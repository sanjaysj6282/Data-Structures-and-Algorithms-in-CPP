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



node* merge(node* head1,node* head2){
    node* dummynode = new node(-1);
    node* temp = dummynode;
    node* ptr1 = head1;
    node* ptr2 = head2;

    while(ptr1 != NULL and ptr2 != NULL){
        if(ptr1->data <= ptr2->data){
            temp->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            temp->next = ptr2;
            ptr2 = ptr2->next;
        }
        temp = temp->next;
    }
    while(ptr1 != NULL){
        temp->next = ptr1;
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        temp->next = ptr2;
        ptr2 = ptr2->next;
    }
    temp->next = NULL;

    return (dummynode->next);
}

node* mergeRecursive(node* head1,node* head2){
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;

    node* result;
    if(head1->data <= head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next,head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1,head2->next);
    }
    return result;
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

    display(head1);
    display(head2);
    // node* newhead = merge(head1,head2);
    node* newhead = mergeRecursive(head1,head2);
    display(newhead);
    
    return 0;
}