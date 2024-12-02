class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        for(int idx = 0; idx < strs.size(); idx++){
            int zeros = count(strs[idx].begin(), strs[idx].end(), '0');
            int ones = count(strs[idx].begin(), strs[idx].end(), '1');

            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};

/**

1) Brute Force: Find all possible subsets and find the longest satisfying the given condition.
TC => O(2^N*N*avgLen)
SC => O(2^N*N)

2) DP: Memoization
There are 𝑘 binary strings, and for each string, we calculate for 𝑚×𝑛 states.
Counting zeros and ones for each string takes 𝑂(avgLen).
Total time complexity => O(k*m*n) + O(k*avgLen)

SC => O(k*m*n) + O(k)(Recursion Stack Space)

3) DP: Tabulation
TC => O(k*m*n) + O(k*avgLen)
SC => O(m*n)

**/
