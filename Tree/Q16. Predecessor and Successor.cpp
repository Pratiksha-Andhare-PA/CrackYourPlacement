// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Traverse the tree to find the predecessor and successor
        while(root){
            if(key < root->key){
                // If key is smaller, root is a potential successor
                suc = root;
                root = root->left;
            }
            
            else if(key > root->key){
                // If key is greater, root is a potential predecessor
                pre = root;
                root = root->right;
            }
            
            else{
                // Key is found
                
                // Find predecessor: largest value in the left subtree
                if(root->left){
                    Node* temp = root->left;
                    while(temp->right){
                        temp = temp->right;
                    }
                    pre = temp;
                }
                
                // Find successor: smallest value in the right subtree
                if(root->right){
                    Node* temp = root->right;
                    while(temp->left){
                        temp = temp->left;
                    }
                    suc = temp;
                }
                
                break; // Key found, no further traversal needed
            }
        }
    }
};


/**

TC: 
Avg => O(logN)
Worst => O(N)

SC => O(1)

**/
