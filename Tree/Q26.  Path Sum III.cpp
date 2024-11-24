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
    int dfs(TreeNode* root, int targetSum, long long sum, unordered_map<long long, int> &prefixSum){
        if(root == NULL) return 0;
        
        sum += root->val;
        int cnt = prefixSum[sum - targetSum];

        prefixSum[sum]++;

        cnt += dfs(root->left, targetSum, sum, prefixSum);
        cnt += dfs(root->right, targetSum, sum, prefixSum);

        prefixSum[sum]--; // backtrack

        return cnt;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;

        // Base case to handle when a path equals targetSum
        // (sum - target) = 0
        prefixSum[0] = 1;  

        return dfs(root, targetSum, 0, prefixSum);
    }
};

/**

# Approaches:

1) Brute Force:
Calculate possible paths sum upto targetSum at each node

TC => O(N^2)
SC => O(h)

2) Maintain unordered_map to store prefix sum till that node 
& then backtrack

TC => O(N)
SC => O(h)

**/
