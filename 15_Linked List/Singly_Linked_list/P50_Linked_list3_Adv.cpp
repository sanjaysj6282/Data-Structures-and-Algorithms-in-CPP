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

int length(node* head){
    int l = 0;
    node* temp = head;

    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

void intersect(node* head1,node* head2,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next!=NULL){
       temp2=temp2->next; 
    }
    temp2->next = temp1;
}

int intersection(node* head1,node* head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
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

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

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
    display(head1);
    display(head2);
    // node* newhead = merge(head1,head2);
    node* newhead = mergeRecursive(head1,head2);
    display(newhead);

    node* head = NULL;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        insertAtTail(head,arr[i]);
    }
    evenAfterodd(head);

    node* head11 = NULL;
    int ar[] = {1,2,3,4,5,6};
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        insertAtTail(head11,ar[i]);
    }
    node* head12 = NULL;
    int a[] = {9,10};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        insertAtTail(head12,ar[i]);
    }
    intersect(head11,head12,3);
    cout << intersection(head11,head12) << endl;;
    
    return 0;
}