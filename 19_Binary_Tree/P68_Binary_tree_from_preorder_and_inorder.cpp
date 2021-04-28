#include <iostream>
using namespace std;
/*
    Algorithm

    1. Pick element from preorder and create node
    2. Increment preorder idx
    3. Search for picked element's pos in order
    4. Call to build left subtree from inorder's 0 to pos-1
    5. Call to build right subtree from inorder's pos+1 to n
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
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start,int end){
    static int idx=0;

    if(start>end)
        return NULL;

    int curr = preorder[idx];
    Node* node = new Node(curr);
    idx++;

    if(start == end)
        return node;

    int pos =search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder,start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);

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
    int preorder[]={1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    // Build tree
    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}