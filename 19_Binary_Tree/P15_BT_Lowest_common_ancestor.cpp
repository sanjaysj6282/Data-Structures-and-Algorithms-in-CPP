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

// Tricky
// Pass by reference Since path is globally changed
bool getPath(Node* root,int key, vector<int> &path){
    // Base case
    if(root == NULL) 
        return false;

    path.push_back(root->data);
    if(root->data == key)
        return true;

    // Recursive case
    if(getPath(root->left,key, path) || getPath(root->right,key, path))
        return true;
    
    // If current root doesnt exist in tree/path
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1,int n2){
    vector<int> path1;
    vector<int> path2;

    if(!getPath(root, n1 , path1) || !getPath(root, n2 , path2))
        return -1;

    int pc;
    for(pc=0; pc<path1.size() and path2.size(); pc++){
        if(path1[pc] != path2[pc])
            break;
    }
    // Its the point of path change
    return path1[pc-1];
}

// O(N) more optimised Since we traverse only once
Node* LCA2(Node* root, int n1, int n2){
    // Base case
    if(root == NULL) 
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    // Recursive case --> Here there are 2
    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA and rightLCA) //both are not NULL
        return root;
    
    if(leftLCA != NULL)
        return leftLCA;
    
    return rightLCA;
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
    int n2 = 4;
    int lca= LCA(root, n1, n2);
    if(lca == -1)
        cout << "LCA doesn't exist " << endl;
    else
         cout << "LCA : " << lca << endl;

    Node* lca2= LCA2(root, n1, n2);
    if(lca2 == NULL)
        cout << "LCA doesn't exist " << endl;
    else
         cout << "LCA : " << lca2->data << endl;


    return 0;
}