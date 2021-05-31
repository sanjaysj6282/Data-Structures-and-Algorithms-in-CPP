#include <iostream>
#include <queue>
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

void printlevelOrder(Node* root){
    if(root==NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout << node->data << " ";
            if(node->left) // Check if there is any node in left
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())// i.e, !q.empty() and node==NULL
            q.push(NULL); 
    }
};

int main(){
    /*  
            1
           / \
          2   3
         / \ / \
        4  5 6  7
                
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printlevelOrder(root);

    return 0;
}