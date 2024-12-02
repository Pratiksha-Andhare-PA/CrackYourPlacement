class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        if(n == 1) return {0, 1};

        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (i&1) ? dp[i/2] + 1 : dp[i/2];
        }

        return dp;
    }
};

/**

# Approaches:
1) Brute Force:
Traverse from 0 to n and find set bits in each number.
TC => O(N*logN)
SC => O(N)

2) Optimal:
The X can be odd or even. 

Case 1: X is odd 
If X is odd then the last bit or Least Significant Bit of the X would be set. 
Dividing by 2 means left shifting the bits 1 time, If we left shift the bits, the Least Significant Bit is Lost. 
That is one set bit is lost in the X.  We know that X/2 is nothing but Y, so the Y has one less set bit than X.

So, No. of set bits in X - No. of set bits in Y = 1

Case 2: X is even 
If X is even then the last bit or Least Significant Bit of the X would be unset. 
Upon the left shift of the bits, the Least Significant Bit is Lost. 
That is one unset bit is lost in the X. So No of the set bits remained unchanged even after dividing by 2.

So, No. of set bits in X - No. of set bits in Y = 0

In both cases combined we can say,
No. of set bits in X - No. of set bits in Y <= 1


If X is odd 
No of Set Bits in X = No of Set Bits in X/2 +1 

If X is even 
No of Set Bits in X = No of Set Bits in X/2 

TC => O(N)
SC => O(N) 

**/
