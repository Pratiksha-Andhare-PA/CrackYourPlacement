class Solution {
    void dfs(vector<vector<int>> &adj, int start, vector<int> &vis, vector<int> &ans){
        vis[start] = 1;
        ans.push_back(start);
        
        for(auto it : adj[start]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(adj, it, vis, ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        
        dfs(adj, 0, vis, ans);
        
        return ans;
    }
};

/**

=> In an undirected graph, each edge is stored twice.
TC => O(V + 2E)
SC => O(V + 2E)

**/
