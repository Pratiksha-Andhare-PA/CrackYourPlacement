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
    void Inorder(TreeNode* root, TreeNode* &prev, int &ans){
        if(root == NULL) return;

        Inorder(root->left, prev, ans);

        if(prev){
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        Inorder(root->right, prev, ans);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        Inorder(root, prev, ans);

        return ans;
    }
};




/**

Approach: 

1) Brute Force	
TC => O(N^2)	
SC => O(N)
Inefficient, compares all pairs of nodes.

2) Optimal 1: Sorted Array	
TC => O(N)	
SC => O(N) Uses vector for in-order values.

3) Optimal 2: In-Place Traversal	
TC => O(N)
SC => O(h)	Most efficient, no extra array.

**/
