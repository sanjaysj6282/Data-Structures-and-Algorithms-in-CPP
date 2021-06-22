#include <iostream>
using namespace std;
/*
    Algorithm

    1. Pick element from end of postorder and create node (Since root is at end)
    2. Decrement postorder idx
    3. Search for picked element's pos in order
    4. Call to build right subtree from inorder's pos+1 to n
    5. Call to build left subtree from inorder's 0 to pos-1
    6. Return the node
*/

struct Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++)
        if(inorder[i] == curr)
            return i;
    
    return -1;
}

// Post is completely opposite to inorder
Node* buildTree(int postorder[], int inorder[], int start,int end){
    // static int idx = sizeof(postorder)/sizeof(postorder[0]);
    // Since root is at end in postorder
    static int idx = 4;

    // Base case
    if(start>end)
        return NULL;

    int curr = postorder[idx];
    Node* node = new Node(curr);
    idx--;

    // If there is only 1 element
    if(start==end)
        return node;

    int pos =search(inorder, start, end, curr);
    node->right = buildTree(postorder, inorder, pos+1, end);
    node->left = buildTree(postorder, inorder,start, pos-1);

    return node;
}

void inorderPrint(Node* root){
    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(){
    int postorder[]={4,2,1,5,3};
    int inorder[] = {4,2,1,5,3};

    // Build tree
    Node* root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}