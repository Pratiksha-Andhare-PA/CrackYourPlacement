class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*, long long>> q;
        long long ans = 0;

        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            long long mnPos = q.front().second;
            long long first, last;

            for(int i = 0; i < n; i++){
                long long currIdx = q.front().second - mnPos;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = currIdx;
                if(i == n-1) last = currIdx;

                if(node->left) q.push({node->left, 2*currIdx + 1});
                if(node->right) q.push({node->right, 2*currIdx + 2});
            }

            ans = max(ans, (last - first + 1));
        }
        return ans;
    }
};

/**

TC => O(N)
SC => O(N)

**/
