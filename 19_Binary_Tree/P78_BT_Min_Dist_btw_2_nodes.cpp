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

// Easy if u know LCA
// Strategy
/*
    1. Find the LCA
    2. Find dist of n1(d1) and n2(d2) from LCA 
       (Dist can be found by no. of levels btw them)
    3. return(d1+d2)
*/

Node* LCA(Node* root, int n1, int n2){
    // Base case
    if(root == NULL) 
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    // Recursive case --> Here there are 2
    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA and rightLCA) //both are not NULL
        return root;
    
    if(leftLCA != NULL)
        return leftLCA;
    
    return rightLCA;
}

int findDist(Node* root, int k, int dist){
    // Base case
    if(root == __null)
        return -1;

    if(root->data == k)
        return dist;

    int left = findDist(root->left, k, dist+1);
    if(left != -1)
        return left;

    // else
    return findDist(root->right, k, dist+1);
}

int distBtwNodes(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);

    // DIst btw lca and n1 and n2 respectively
    int d1 = findDist(lca,n1,0);
    int d2 = findDist(lca,n2,0);

    return d1+d2;

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

    int n1 =7;
    int n2 = 8;

    cout << distBtwNodes(root, n1, n2);


    return 0;
}