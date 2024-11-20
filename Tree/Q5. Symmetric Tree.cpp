class Solution {
    bool helper(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;

        if(!a || !b) return false;

        if(a->val != b->val) return false;

        return helper(a->left, b->right) && helper(a->right, b->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return helper(root->left, root->right);
    }
};

/**

TC => O(N)
SC => O(h)

**/
