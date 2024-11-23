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
    vector<TreeNode*> helper(int st, int en){
        vector<TreeNode*> ans;

        if(st > en){
            ans.push_back(NULL);
            return ans;
        }

        for(int i = st; i <= en; i++){
            vector<TreeNode*> leftSubTrees = helper(st, i-1);
            vector<TreeNode*> rightSubTrees = helper(i+1, en);

            for(auto x : leftSubTrees){
                for(auto y : rightSubTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return {};
        }

        return helper(1, n);
    }
};

/**

TC & SC => Exponential

**/
