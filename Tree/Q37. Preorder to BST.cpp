class Solution {
    
    Node* construct(int pre[], int &idx, int mn, int mx, int n){
        if(idx >= n) return NULL;
        
        
        int key = pre[idx];
        if(key <= mn || key >= mx) return NULL;
        
        Node* root = newNode(key);
        idx++;
        
        if(idx < n) root->left = construct(pre, idx, mn, key, n);
        
        if(idx < n) root->right = construct(pre, idx, key, mx, n);
        
        return root;
    }
    
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        int idx = 0;
        return construct(pre, idx, INT_MIN, INT_MAX, size);
    }
};

/**

# Approaches:

1) Brute Force:
Traverse the preorder array and Insert nodes in tree one by one

TC => O(N^2)
SC => O(H)

2) Optimal: Pass Range in Recursion(min, max)

TC => O(N)
SC => O(H)

**/
