// #include <iostream>
// using namespace std;

// struct Node{
//     public:
//     int data;
//     struct Node* left;
//     struct Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node* insertBST(Node* root, int val){
//     if(root == __null)
//         return (new Node(val));
    
//     if(val < root->data)
//         root->left = insertBST(root->left, val);
    
//     else if(val > root->data)
//         root->right = insertBST(root->right, val);

//     return root;
// }

// void inorder(Node* root){
//     if(root == NULL)
//         return;
    
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }



// Node* inorderSucc(Node* root){
//     Node* curr = root;
//     while(curr and curr->left != NULL)
//         curr = curr->left;
    
//     return curr;
// }

// Node* deleteInBST(Node* root, int val){
//     if(val < root->data)
//         root->left = deleteInBST(root->left, val);

//     else if(val > root->data) 
//         root->left = deleteInBST(root->left, val);

//     else{
//         if(root->left == NULL){
//             Node* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right == NULL){
//             Node* temp = root->left;
//             free(root);
//             return temp;
//         }
//         else{
//             Node* temp = inorderSucc(root->right);
//             root->data = temp->data;
//             root->right = deleteInBST(root->right, temp->data);
//         }
//     }
//     return root;
// }



// int main(){
//     Node* root =  NULL;
//     root = insertBST(root, 4);
//     insertBST(root, 2);
//     insertBST(root, 5);
//     insertBST(root, 1);
//     insertBST(root, 3);
//     insertBST(root, 6);

//     inorder(root);
//     cout << endl;

//     if(searchInBST(root, 6) == NULL)
//         cout << "Key doesn't exist " << "\n";
//     else
//         cout << "Key exist " << "\n";
    
//     root = deleteInBST(root, 5);
//     inorder(root);
//     cout << endl;

//     return 0;

//     //inorder(root);

//     return 0;
// }