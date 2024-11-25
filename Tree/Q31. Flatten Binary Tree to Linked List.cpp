class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

/**

# Complexity Analysis:

TC => O(N) + O(N) ~ O(N)
SC => O(1)

**/
