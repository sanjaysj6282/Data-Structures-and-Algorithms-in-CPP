#include <iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node *left,*right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

// VIMP
/*  Approach 1  ->Wrong (think why)
    Node > left child
    Node < right child

    Approach 2
    root/node > max of left subtree(maxL)
    root/node < max of right subtree(minR)

    Approach 3  (modified approach 2)
    min allowed < node
    max allowed > node   
*/

/*  
    Strategy
            node(min,max)
            /           \
    left(min,node)   right(node,max)
*/

bool checkBST(Node* root, Node* min=NULL, Node* max=NULL){
    if(root == NULL)
        return true;

    if(min != NULL and root->data <= min->data) 
        return false;
    
    if(max != NULL and root->data >= max->data)
        return false;
    
    bool leftValid = checkBST(root->left, min, root);
    bool rightValid = checkBST(root->right, root, max);

    return leftValid and rightValid;
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    if(checkBST(root1, NULL, NULL))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << "\n";    

    return 0;
}