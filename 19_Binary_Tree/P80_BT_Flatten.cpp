#include <iostream>
#include <vector>
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

// VIMP
// Strategy
/*
    Steps
    1. Recursively flatten the left and right subtrees
    2. Store the left tail and right tail
    3. a) Store right subtree in temp and 
       b) make left subtree as right subtree
    4. Join right subtree with left tail
    5. Return right tail

*/

void flatten(Node* root){
    // Base case
    if(root == NULL || (root->left == NULL and root->right == NULL))
        return;

    if(root->left != NULL){ // If its NULL, there is no left subtree
        flatten(root->left);      // Step 1

        // Easy think normally
        Node* temp = root->right; // Step 3 --> a)
        root->right = root->left; //            b)
        root->left = NULL;        // To nullify the left blank space

        Node* t = root->right;    // Step 2 --> To find right tail
        while(t->right != NULL)   // i.e, Earlier left tail
            t = t->right;
        
        // Actually we connect left tail to right head
        t->right = temp;          // Step 4
    }
    flatten(root->right);         // Step 1
}

void inorderPrint(Node* root){
    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}


int main(){
/*
        4              4                       
       / \              \
      9   5              9
     / \   \              \
    1   3   6              1
                            \
                             3
                              \ 
                               5
                                \
                                 6
*/

    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    flatten(root);
    inorderPrint(root);

    return 0; 
}