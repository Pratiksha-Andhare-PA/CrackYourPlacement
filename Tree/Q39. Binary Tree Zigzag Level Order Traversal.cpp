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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        vector<int> arr;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int cnt = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            
            if(temp != NULL){
                q.pop();
                arr.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            else{
                q.pop();

                if(cnt%2 != 0){
                    reverse(arr.begin(), arr.end());
                }
                ans.push_back(arr);
                arr.clear();

                cnt++;
                
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};

/**

Use Level Order Traversal

Time Complexity: O(N+L) 
where 𝑁 is the number of nodes and 
𝐿 is the total number of elements reversed (all levels combined). In the worst case, 
𝐿 = 𝑁/2 so 𝑂(𝑁+𝐿)=𝑂(𝑁)

Space Complexity: O(N) => Queue 

**/
