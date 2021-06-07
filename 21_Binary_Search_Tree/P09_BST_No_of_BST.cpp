#include <iostream>
#include <vector>
using namespace std;

// VIMP Concept
// Application of Catalan Numbers

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

void printPreorder(Node* root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

vector<Node*> constructTree(int start, int end){
    vector<Node*> trees;

    // Base case
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        // To get all possible left and right nodes respectively
        vector<Node*> leftSubtrees = constructTree(start, i-1);
        vector<Node*> rightSubtrees = constructTree(i+1, end);

        // Taking all nodes and combining
        for(int j=0; j<leftSubtrees.size(); j++){
            Node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++){
                Node* right=rightSubtrees[k];

                // Current node to which left and right subtrees are added
                Node* node = new Node(i);
                node->left = left;
                node->right = right;

                trees.push_back(node);
            }
        } 
    }

    return trees;
}

int main(){
    vector<Node*> totalTrees = constructTree(1, 3);
    for(int i=0; i<totalTrees.size(); i++){
        cout << (i+1) << " : ";
        printPreorder(totalTrees[i]);
        cout << endl;
    }

    return 0;
}