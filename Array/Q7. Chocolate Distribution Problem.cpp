class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        
        int ans = INT_MAX;
        for(int i = 0; i <= a.size()-m; i++){
            ans = min(ans, (a[i + m - 1] - a[i]));
        }
        
        return ans;
    }
};


/*

<========= Approach =========>

Sort the array and find the minimum difference by taking m sized window.

TC => O(N*logN)
SC => O(1)

*/
