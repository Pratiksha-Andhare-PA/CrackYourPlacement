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
    bool balanced(TreeNode* root, int *ht){
        if(root == NULL){
            *ht = 0;
            return true;
        }

        int lh = 0, rh = 0;
        if(!balanced(root->left, &lh)) return false;
        if(!balanced(root->right, &rh)) return false;

        *ht = 1 + max(lh, rh);

        return (abs(lh - rh) <= 1);
    }

public:
    bool isBalanced(TreeNode* root) {
        int ht = 0;
        return balanced(root, &ht);
    }
};

/**

# Approaches
1) Brute Force: Calculate height at each node.
TC => O(N^2)
SC => O(h) ~ O(logN)

2) Optimal: Maintain height pointer
TC => O(N)
SC => O(h) ~ O(logN)

**/
