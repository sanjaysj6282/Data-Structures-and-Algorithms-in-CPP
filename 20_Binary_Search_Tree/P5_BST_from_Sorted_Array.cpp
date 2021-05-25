#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left,*right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

// Idea
/*
    Steps
  1. Make middle element from array
  2. Recursively do the same for for subtrees
    a. start to mid-1 for left subtree
    b. mid+1 to end for righ
*/

Node* build(int arr[], int start, int end){

    if(start > end)
        return NULL;
    
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);

    root->left = build(arr, start, mid-1);
    root->right = build(arr, mid+1, end);
    
    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int arr[] = {1,2,3,4,5};
    Node* root = build(arr,0,4);

    inorder(root);

    return 0;
}