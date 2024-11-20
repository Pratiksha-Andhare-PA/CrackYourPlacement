class Solution {
    TreeNode* BuildBST(vector<int> &nums, int left, int right){
        if(left > right) return NULL;

        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = BuildBST(nums, left, mid-1);
        root->right = BuildBST(nums, mid+1, right);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildBST(nums, 0, nums.size() - 1);
    }
};

/**

TC => O(N)
SC => O(h) ~ O(logN)

**/
