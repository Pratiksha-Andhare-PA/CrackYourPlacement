class Solution {
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;

        if(!root || !subRoot) return false;

        if(root->val != subRoot->val) return false;

        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;

        if(!root) return false;

        if(isSame(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

/**

TC => O(N*M) => N: Total no. of nodes in Main Tree & M: Total no. of nodes in Subtree.

SC => O(h1 + h2)
Balanced Tree: h1 => N & h2 => M
Skewed Tree: h1 = O(logN) & h2 = O(logM)

**/
