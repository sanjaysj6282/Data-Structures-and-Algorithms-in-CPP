#include <iostream>
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

// O(N)
int calcHeight(Node* root){
    if(root==NULL)
        return 0;
    // Similar to finding no of nodes (compare and analyse)
    return max(calcHeight(root->left),calcHeight(root->right))+1;
}

// 0(N*N) Since calHeight is multiplies by N (by calcDiameter)
int calcDiameter(Node* root){

    if(root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}

// O(N)
int calcDiameter2(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int lDiameter = calcDiameter2(root->left,&lh);
    int rDiameter = calcDiameter2(root->right,&rh);

    int currDiameter = lh+rh+1;
    *height = max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main(){

    /*  
            1
           / \
          2   3
         / \ / \
        4  5 6  7
                 \
                  8
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
        root->right->right->right = new Node(8);

    cout << calcHeight(root) << endl;
    cout << calcDiameter(root) << endl;

    int height = 0;
    cout << calcDiameter2(root,&height) << endl;

    return 0;
}