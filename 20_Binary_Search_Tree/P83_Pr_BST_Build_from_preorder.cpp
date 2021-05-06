#include <iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

void printPreorder(Node* root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

Node* constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n)
        return NULL;

    Node* root = NULL;
    if(key > min and key < max){
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n)
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx],min, key, n);
        
        if(*preorderIdx < n)
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx],key, max, n);
    }
    return root;
}

int32_t main(){
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT16_MIN, INT16_MAX, n);
    printPreorder(root);

    return 0;
}