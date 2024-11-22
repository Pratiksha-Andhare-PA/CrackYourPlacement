class Solution{
    bool checkDeadEnd(Node* root, int mnVal, int mxVal){
        if(!root) return false;
        
        if(mnVal == mxVal) return true;
        
        return checkDeadEnd(root->left, mnVal, root->data - 1) ||
               checkDeadEnd(root->right, root->data + 1, mxVal);
    }
    
  public:
    bool isDeadEnd(Node *root)
    {
        return checkDeadEnd(root, 1, INT_MAX);
    }
};

/**

TC => O(N)
SC => O(h)

**/
