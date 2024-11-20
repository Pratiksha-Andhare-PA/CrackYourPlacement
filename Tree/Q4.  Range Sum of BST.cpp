class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        int ans = 0;
        if(root->val >= low && root->val <= high){
            ans += root->val;
        }

        if(root->val > low){
            ans += rangeSumBST(root->left, low, high);
        }

        if(root->val < high){
            ans += rangeSumBST(root->right, low, high);
        }
        return ans;
    }
};

/**

#Approaches
1) Brute Force:
Create a vector store all the node values in range in vector by traversing the tree.
Sum it and return.

TC => O(N)
SC => O(N)

2) Traverse the entire tree and check if it's in range and add to answer if yes.
TC => O(N)
SC => O(h)

3) Traverse the tree by using the BST property.
TC => O(h + k)
SC => O(h)

**/
