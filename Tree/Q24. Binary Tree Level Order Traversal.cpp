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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> arr;
        while(!q.empty()){
            TreeNode* temp = q.front();

            if(!temp){
                q.pop();
                ans.push_back(arr);
                arr.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                q.pop();
                arr.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};

/**

# Complexity Analysis:

TC => O(N)
SC => O(W + N) ~ O(N) in worst case.

W => Width of BST
For perfect Binary Tree, W ~ (N/2)
For Skewed Tree, W = 1

**/
