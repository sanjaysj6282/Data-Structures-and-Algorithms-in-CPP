#include <iostream>
#include <vector>
#include <climits>  
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
// Difficult

// Algorithm
/*
    For each Node, compute
 1. Node val
 2. Max path through left child + node val
 3. Max path through right child + node val
 4. Max path through left child + Max path through rt child + Node val

*/

int maxPathsumutil(Node* root,int &ans){
    if(root == NULL)
        return 0;
    
    // Sum through left and right node of a tree
    int left = maxPathsumutil(root->left,ans);
    int right = maxPathsumutil(root->right,ans);

    // To find max value from a node
    // i.e, value of node + value from right and left i.e, left&right
    //   OR value of node + value of left and node + right
    int nodeMax = max(max(root->data,root->data + left+ right),
                      max(root->data + left,root->data + right));

    ans = max(ans,nodeMax);

    // Considering value passing through root
    int singlePathsum = max(root->data, 
                            max(root->data + left, root->data + right));
    return singlePathsum;
}

int maxPathsum(Node* root){
    int ans = INT_MIN;
    maxPathsumutil(root, ans);
    return ans;
}

int main(){
    /*  
            1
           / \
          2   3
         / \ / \
        4  5 6  7
          /
        8    
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);

    cout << maxPathsum(root);

    return 0;
}