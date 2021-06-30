#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//  Strategy
/*  
    1. If both empty, return true
    2. If both non-empty
        a. Check that the data at nodes is equal
        b. Check if left subtrees are same
        c. Check if right subtrees are same
    3. If (a,b,c) are true, return true
       else, return false
*/

bool isIdentical(Node* root1, Node* root2){
    // if((root1==NULL and root2!=NULL)and (root1!=NULL and root2==NULL))
    //     return false;

    // if(root1==NULL and root2==NULL)
    //     return true;

    // bool leftsub = isIdentical(root1->left,  root2->left);
    // bool rightsub = isIdentical(root1->right,  root2->right);

    // if(root1->data == root2->data and leftsub == 1 and rightsub == 1)
    //     return true;
    // else
    //     return false;

    
    // OR
    // Better Code(in term of understanding)

    if(root1==NULL && root2==NULL)
        return true;

    else if(root1==NULL || root2==NULL)
        return false;

    else{
        bool cond1 = root1->data ==root2->data;
        bool cond2 = isIdentical(root1->left,  root2->left);
        bool cond3 = isIdentical(root1->right,  root2->right);

        if(cond1 && cond2 && cond3)
            return true;
        
        return false;
    }
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

    /*
            12
           /  \
          9    15
         / \   
        5   1
    */

    Node* root1 = new Node(12);
    root1->left = new Node(9);
    root1->right = new Node(15);
    root1->left->left = new Node(5);
    root1->left->right = new Node(1);

    if(isIdentical(root, root1))
        cout << "BSTs are Identical" << "\n";
    else
        cout << "BSTs are non Identical" << "\n";

    return 0;
}