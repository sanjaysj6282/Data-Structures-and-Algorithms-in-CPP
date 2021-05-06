#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = __null;
    }
};

// Strategy
/* 
    For each node store
    1. min in subtree
    2. max in subtree
    3. subtree size
    4. size of largest BST
    5. isBST

    Recursively traverse in a bottom-up manner and find 
    out the size of largest BST
*/

struct Info{
    int min;
    int max;
    int size;
    int ans;
    bool isBST;
};

// Hard
Info largestBST(Node* root){
    if(root == NULL)
        // Default value
        return {INT_MAX, 0, INT_MIN, 0, true};
    
    // Check leaf node
    if(root->left == NULL and root->right == __null)
        return {root->data, root->data, 1, 1, true};

    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right); 

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    // To check wheather BST forms at "curr"
    if(leftInfo.isBST && rightInfo.isBST && 
       leftInfo.max < root->data && rightInfo.min > root->data){

        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    // else
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;

    return curr;
}

int main(){
    /*
            12
           /  \
          9    15
         / \   
        5   10
    */
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    cout << "Largest BST in BT : " << largestBST(root).ans << "\n";

    return 0;
}