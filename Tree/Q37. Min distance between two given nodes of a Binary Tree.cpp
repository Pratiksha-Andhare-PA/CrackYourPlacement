class Solution{
    Node* LCA(Node* root, int a, int b){
        if(root == NULL) return NULL;
        
        if(root->data == a || root->data == b) return root;
        
        Node* left = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        
        if(left == NULL) return right;
        
        if(right == NULL) return left;
        
        return root;
    }
    
    int distToLCA(Node* root, int node, int dist){
        if(root == NULL) return -1;
        
        if(root->data == node) return dist;
        
        int left = distToLCA(root->left, node, dist + 1);
        
        if(left != -1) return left;
        
        return distToLCA(root->right, node, dist + 1);
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        
        int distAtoLCA = distToLCA(lca, a, 0);
        int distBtoLCA = distToLCA(lca, b, 0);
        
        return distAtoLCA + distBtoLCA;
    }
};

/**

TC => O(N)
SC => O(H)

**/
