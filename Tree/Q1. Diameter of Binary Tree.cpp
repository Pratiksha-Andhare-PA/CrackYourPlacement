class Solution {
    int calcDia(TreeNode* root, int *Height){
        if(root == NULL){
            Height = 0;
            return 0;
        }

        int lh = 0, rh = 0;
        int leftDia = calcDia(root->left, &lh);
        int rightDia = calcDia(root->right, &rh);

        *Height = max(lh, rh) + 1;
        int currDia = lh + rh;

        return max(currDia, max(leftDia, rightDia));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int Height = 0;
        return calcDia(root, &Height);
    }
};

/**

# Approaches:

1) Brute Force:
The brute force implementation computes the diameter of the binary tree by:

Calculating the height of the left and right subtrees for every node using a separate recursive call.
Recursively calculating the diameter for the left and right subtrees.

TC => O(N^2)
SC => O(h), O(N) in worst case

2) Optimal:
The optimal approach calculates the diameter and height of the tree in a single traversal:
During the recursive call, it calculates the height and simultaneously updates the diameter.

TC => O(N)
SC => O(h)

**/
