class Solution {
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n){
        // Base case: Check if we are out of bounds or if the cell is water ('0')
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;

        // Mark the cell as visited by setting it to '0'
        grid[i][j] = '0';

        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                // If the cell is land ('1'), start a DFS
                if(grid[i][j] == '1'){
                    cnt++;                   // Found a new island
                    dfs(grid, i, j, m, n);   // Mark the entire island as visited
                }
            }
        }
        return cnt;
    }
};

/**

# Approaches:

1) DFS:
TC => O(M*N)
SC => O(M*N)

2) BFS:
TC => O(M*N)
SC => O(M*N)

**/
