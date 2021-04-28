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

int sumAtKthlevel(Node* root,int k){
    if(root==NULL)
        return -1;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int sum=0;
    int level=0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            if(level==k){
                sum += node->data;
            }
            if(node->left) // Check if there is any node in left
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){// i.e, !q.empty() and node==NULL
            q.push(NULL); 
            level++;
        }
    }
    return sum;
}

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

    cout << sumAtKthlevel(root,2) << endl;

    return 0;
}