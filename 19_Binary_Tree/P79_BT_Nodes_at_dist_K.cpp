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

// Strategy
/*
    Case 1 --> Node's Subtree
    We reduce K till K=0; i.e, it go down tree;

    Case 2 --> Node's Ancestors
    1. Find the dist of all ancestor from target node(d)
    2. For all ancestors --> search other subtree for nodes at (K-d)
     i.e, If node is rt to ancestor search for left of ancestor
          If node is left to ancestor search for rt of ancestor
    Also, Its converting Case2 --> Case1 

*/

// Case 1
void printSubtreeNodes(Node* root, int k){
    if(root == NULL or k<0)
        return;

    if(k==0){
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);

}


// Difficult

// Case 2
// Return type is int Since its based on distance
// root is the real root and target is the node from we need to find
int printNodesAtk(Node* root, Node* target, int k){
    // Base
    // Didn't get the node
    if(root == NULL)
        return -1;

    if(root == target){
        printSubtreeNodes(root,k);
        return 0;
    }
    
    // dl --> Distance for Left Subtree
    int dl = printNodesAtk(root->left, target, k);
    // To check if there exist such a node
    if(dl != -1){
        // It's for making sure that current node is at K dist from target node 
        if(dl == k-1)
            cout << root->data << " ";
        else
            // Refer srategy
            printSubtreeNodes(root->right, k-dl-2);
            // -2 --> travel towards "Right from Left" subtree(So 2 operations)
        
        // Returns the dist travelled
        return 1+dl;
    }
    
    int dr = printNodesAtk(root->right, target, k);
    if(dr != -1){
        if(dr == k-1)
            cout << root->data << " ";
        else
            printSubtreeNodes(root->left, k-dr-2);
        
        return 1+dr;
    }
    return -1;
}

int main(){
/*  
            1
           / \
          2   3
         / \ / \
        4  5 6  7
          /      \
         8        9
*/
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right->right = new Node(9);

    // From root->left (from 3) we need to find elemts at a dist 2
    printNodesAtk(root, root->right, 2);
    
    return 0;
}