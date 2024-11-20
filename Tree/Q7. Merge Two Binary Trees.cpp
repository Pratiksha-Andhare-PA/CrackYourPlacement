class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = NULL;

        if(root1 && root2){
            root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }

        else if(root1){
            root = new TreeNode(root1->val);
            root->left = mergeTrees(root1->left, NULL);
            root->right = mergeTrees(root1->right, NULL);
        }

        else if(root2){
            root = new TreeNode(root2->val);
            root->left = mergeTrees(NULL, root2->left);
            root->right = mergeTrees(NULL, root2->right);
        }

        return root;
    }
};

/**

TC => O(M + N) Where 𝑛 and 𝑚 are the sizes of root1 and root2, respectively.

SC => O(h) where ℎ is the height of the larger tree.
For balanced trees, space complexity will be O(logn).
For skewed trees, space complexity will be O(n).


**/
