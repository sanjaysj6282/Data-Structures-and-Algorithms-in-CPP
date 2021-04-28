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

int countNodes(Node* root){
    if(root==NULL)
        return 0;

    return countNodes(root->left)+countNodes(root->right)+1;
}

int sumNodes(Node* root){
    if(root==NULL)
        return 0;
    
    return sumNodes(root->left)+sumNodes(root->right) + root->data;
}


int main(){
    /*  
            1
           / \
          2   3
         / \ / \
        4  5 6  7
                
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << countNodes(root) << endl;
    cout << sumNodes(root) << endl;
    
    return 0;
}