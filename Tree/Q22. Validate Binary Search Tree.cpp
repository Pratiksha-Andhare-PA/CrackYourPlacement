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
    bool isValid(TreeNode* root, long long mn, long long mx){
        if(root == NULL) return true;

        if(root->val <= mn || root->val >= mx) return false;

        return isValid(root->left, mn, root->val) && 
                isValid(root->right, root->val, mx);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};


/**

# Approaches:

1) Brute Force:
Calculate min node value of left subtree & max node val of right subtree for each node
& check if it satisfies the BST property.
(every node should be greater than left & smaller than right subtree node values.)

TC => O(N^2)
SC => O(h)

2) Optimal:
Maintain min and max value variables & check for BST property at each node.

TC => O(N)
SC => O(h)

**/
