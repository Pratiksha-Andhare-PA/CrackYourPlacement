class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int prev1 = 1, prev2 = 1;

        for(int i = 2; i <= n; i++){
            int curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};

/**

#Approaches:

1) Brute Force: Recursion(Fibonacci Series)
TC => O(2^N) => Exponential
SC => O(N) => Recursion Stack Space

2) DP: Memoization
TC => O(N)
SC => O(N) + O(N) => Dp array & Recursion Stack Space

3) DP: Tabulation
TC => O(N)
SC => O(N) => Dp array

4) Space Optimization: Use 2 variables to keep track of previous 2 results
TC => O(N)
SC => O(1)

**/
