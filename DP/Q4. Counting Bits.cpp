class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;

        for(int i=1;i<=n;i++){
            // (i/2) => right shift by 1
            // (i%2) => 1 for even and 0 for odd
            dp[i] = dp[i/2] + (i%2);
        }
        return dp;
    }
};
