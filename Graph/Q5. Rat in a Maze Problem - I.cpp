class Solution {
    void dfs(vector<vector<int>> &mat, int i, int j, string path, vector<string> &ans, int n){
        if(i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0) return;
        
        if(i == n - 1 && j == n - 1){
            ans.push_back(path);
            return;
        }
        
        // Mark the cell as visited by setting it to 0
        mat[i][j] = 0;
        
        dfs(mat, i - 1, j, path + 'U', ans, n);
        dfs(mat, i + 1, j, path + 'D', ans, n);
        dfs(mat, i, j - 1, path + 'L', ans, n);
        dfs(mat, i, j + 1, path + 'R', ans, n);
        
        // Restore the cell to its original state (backtracking)
        mat[i][j] = 1;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        
        vector<string> ans;
        
        if(mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return ans;
        
        dfs(mat, 0, 0, "", ans, n);
        return ans;
    }
};

/**

1) Brute Force: dfs

TC => O(4^N*N)
SC => O(N*N)

2) Optimised dfs:
Don't use visited to keep track of cells 
Instead replace values of matrix itself(if allowed)

TC => O(4*N*N)
SC => (N*N)

**/
