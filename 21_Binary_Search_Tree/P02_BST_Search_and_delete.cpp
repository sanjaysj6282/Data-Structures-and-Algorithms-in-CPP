#include <iostream>
using namespace std;

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


Node* insertBST(Node* root, int val){
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insertBST(root->left, val);
    
    else
        root->right = insertBST(root->right, val);

    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}



// Easy
// O(log(n))
Node* searchInBST(Node* root, int key){
    if(root == NULL)
        return NULL;

    if(root->data == key)
        return root;

    else if(root->data < key)
        searchInBST(root->right, key);

    else
        searchInBST(root->left, key);
}

// Tricky
/*
    Cases
    1. Node is leaf
       Delete leaf node

    2. Node has 1 child
       Replace node with child and delte the node

    3. Node has 2 child
       Replace node with inorder successor 
       (i.e, Value just greater than current node)
*/

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL)
        curr = curr->left;
    
    return curr;
}

// VIMP 
// Tricky
Node* deleteInBST(Node* root, int key){

    // Search 
    if(key < root->data)
        root->left = deleteInBST(root->left, key);

    else if(key > root->data)
        root->right = deleteInBST(root->right, key);

    else{ // root->data == key OR root == NULL 

        // Case 1 and 2
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        // Case 1 and 2
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data; // value of root and temp is same
        // Deleting inorderSuccesor pointer
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

int main(){
    Node* root =  NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 6);

    inorder(root);
    cout << endl;

    if(searchInBST(root, 6) == NULL)
        cout << "Key doesn't exist " << "\n";
    else
        cout << "Key exist " << "\n";
    
    root = deleteInBST(root, 5);
    inorder(root);
    cout << endl;

    return 0;
}
