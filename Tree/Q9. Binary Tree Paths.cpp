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
    void BTPaths(TreeNode* root, string path, vector<string> &ans){
        if(root == NULL) return;

        // Append current node value to the path
        path += to_string(root->val);

        // If it's a leaf node, add the path to the answer
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }

        // Otherwise, add "->" and continue for left and right subtrees
        path += "->";

        BTPaths(root->left, path, ans);
        BTPaths(root->right, path, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        BTPaths(root, "", ans);

        return ans;
    }
};


/**

# Complexity Analysis

TC => O(N + E)

Traversal:
Each node is visited once: O(N).

String Concatenation:
At each node, a new string is created using concatenation. For a path of length h, string concatenation takes O(h).
Across all nodes, this results in a total of O(E), where E is the sum of the lengths of all paths.
Total Time Complexity: O(N+E).

SC => O(L)

Call Stack:

The recursion depth depends on the height of the tree, h.
Worst case (skewed tree): O(N).
Best case (balanced tree): O(logN).

Result Storage:
Paths are stored in a vector. The size of the storage depends on the total number of paths and their lengths (L).

Worst case: O(N^2) (in a skewed tree with a single path of length N).

Best case: O(L), where L is the total length of all paths.
Total Space Complexity: O(h+L).

**/
