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


int main(){
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