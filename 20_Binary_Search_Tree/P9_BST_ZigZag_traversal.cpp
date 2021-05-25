#include <iostream>
#include <stack>
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
    Steps
   1. Use 2 stacks - currentLevel & nextlevel
   2. variable LeftToRight
   3. if LeftToRight, 
            push left child then right
      else, 
            push right child then left
*/

void zigzagTraversal(Node* root){
    // Corner case 1
    if(root == NULL)
        return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Node* Top = currLevel.top();
        currLevel.pop();

        // Corner case 2
        if(Top)
            cout << Top->data << " ";
        
        if(leftToRight){
            if(Top->left)
                nextLevel.push(Top->left);
            if(Top->right)
                nextLevel.push(Top->right);
        }
        else{
            if(Top->right)
                nextLevel.push(Top->right);
            if(Top->left)
                nextLevel.push(Top->left);           
        }

        ;

        if(currLevel.empty()){ 
            stack<Node*> temp = currLevel;
            currLevel = nextLevel;
            nextLevel = temp;
            //  OR
            // swap(currLevel,nextLevel);

            leftToRight = !leftToRight;
           
        }
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

    zigzagTraversal(root);

    return 0;
}