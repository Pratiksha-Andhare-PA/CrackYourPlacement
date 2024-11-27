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
    void Inorder(TreeNode* root, int k, int &cnt, int &ans){
        if(root == NULL || cnt >= k) return;

        Inorder(root->left, k, cnt, ans);

        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }

        Inorder(root->right, k, cnt, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans;
        Inorder(root, k, cnt, ans);

        return ans;
    }
};

/**

# Approaches:

1) Brute Force:
Traverse the tree and store all the nodes in a data structure(vector)
Sort the vector in ascending order and return the Kth value

TC => O(N*logN)
SC => O(N)

2) Optimal: Inorder Traversal and a cnt variable
return as soon as cnt == k 

TC => O(H + K)
SC => O(H) => Recursion stack space

**/
