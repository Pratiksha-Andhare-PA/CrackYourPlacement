class Solution {
    void bfs(vector<vector<int>> &adj, int start, int n, vector<int> &ans){
        vector<int> vis(n, 0);
        vis[start] = 1;
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int> ans;
        bfs(adj, 0, adj.size(), ans);
        
        return ans;
    }
};

/**

=> In undirected graph, each edge is stored twice.
TC => O(V + 2E)
SC => O(V + 2E)

**/
