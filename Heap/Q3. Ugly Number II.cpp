class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1; // first ugly no. is 1

        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i++){
            int next2 = dp[p2]*2;
            int next3 = dp[p3]*3;
            int next5 = dp[p5]*5;

            dp[i] = min({next2, next3, next5});

            if(dp[i] == next2) p2++;
            if(dp[i] == next3) p3++;
            if(dp[i] == next5) p5++;
        }
        return dp[n - 1];
    }
};

/**

# Approaches

1) Brute Force:
Traverse numbers from 1 to n and check for each if its ugly or not

TC => O(N*logK) => N for traversal and logK for checking if it's ugly or not where, K is the number for which the check is done.
SC => O(1)

2) Using DP
Generate only the ugly numbers.

TC => O(N)
SC => O(N)

**/
