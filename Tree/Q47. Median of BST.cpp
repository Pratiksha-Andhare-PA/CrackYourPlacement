void Inorder(struct Node *root, vector<int> &ans){
    if(root == NULL) return;
    
    Inorder(root->left, ans);
    
    ans.push_back(root->data);
    
    Inorder(root->right, ans);
}

float findMedian(struct Node *root)
{
      vector<int> ans;
      Inorder(root, ans);
      
      int n = ans.size();
      
      if(n%2 != 0) return ans[n/2];
      
      return (ans[(n/2 - 1)] + ans[n/2]) / 2.0;
}

/**

# Complexity:

TC => O(N)
SC => O(N) + O(H)

**/
