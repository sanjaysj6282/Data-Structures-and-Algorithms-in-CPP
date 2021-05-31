#include <iostream>
#include <vector>
#include <map>
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
/*

   Approach (Using hashing)
1. Create a map (say hd) whose keys store the distance from the node and
   value stores a vector of nodes at the respective horizontal distance.
2. Start from the root node and recursively call left and right child with (hd-1)
   and (hd+1) as arguments.

   Base Case:
   if(current_node == NULL)
      return;
3. Push the value into the vector corresponding to the horizontal 
   distance(hd).
4. Output the map

*/

map<int, vector<int>> mp;

void getVerticalOrder(Node* root,int hd=0){
    if(root == NULL) 
        return;

     mp[hd].push_back(root->data);

    getVerticalOrder(root->left, hd-1);
    getVerticalOrder(root->right, hd+1);
}
int main(){
    /*  
            1
           / \
          2   3
         / \ / \
        4  56  7
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
    
    getVerticalOrder(root);

    map<int, vector<int>> :: iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        for(int i=0; i<it->second.size(); i++)
            cout << it->second[i] << " ";
        cout << endl;
    }

    return 0;
}