class Solution {
    void permute(vector<int> &arr, int idx, int n, set<vector<int>> &uniquePermute){
        if(idx == n){
            uniquePermute.insert(arr);
            return;
        }
        
        for(int i = idx; i < n; i++){
            swap(arr[idx], arr[i]);
            permute(arr, idx + 1, n, uniquePermute);
            swap(arr[idx], arr[i]);
        }
    }
    
    
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        
        set<vector<int>> uniquePermute;
        permute(arr, 0, n, uniquePermute);
        
        vector<vector<int>> ans(uniquePermute.begin(), uniquePermute.end());
        
        return ans;
    }
};

/*

TC => O(N * N!)
SC => O(N * N!)

*/
