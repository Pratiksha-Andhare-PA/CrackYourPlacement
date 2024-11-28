/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode* root, int &ans){
        if(root == NULL) return 0;

        // Get the maximum path sum of left and right subtrees
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);

        // Maximum path sum starting from the current node to one of its children
        int mxSingle = max((max(l, r) + root->val), root->val);

        // The maximum path sum that can pass through the current node 
        // (including both left and right children)
        int mxTop = max(mxSingle, l + r + root->val);

        // Update the global answer
        ans = max(ans, mxTop);

        // Return the maximum sum that can be extended upwards (to the parent node)
        return mxSingle;
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);

        return ans;
    }
};

/**

# Complexity:
TC => O(N)
SC => O(H)

**/
