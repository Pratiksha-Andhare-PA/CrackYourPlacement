class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> remainder(k, 0);
        int currSum = 0;
        for(int i = 0; i < n; i++){
            currSum += nums[i];
            remainder[((currSum % k) + k) % k]++;
        }

        long long ans = 0;
        for(int i = 0; i < k; i++){
            if(remainder[i] > 1){
                ans += (static_cast<long long>(remainder[i]) * (remainder[i] - 1)) / 2;
            }
        }
        ans += remainder[0];
        return ans;
    }
};

/*

1) Brute Force:
Calculate the sum for all possible subarrays and check if it's divisible by k or not.
If yes, then increment the count and return the count.

TC => O(N*N)
SC => O(1)

2) Let there be a subarray (i, j) whose sum is divisible by k
  sum(i, j) = sum(0, j) - sum(0, i-1)

Sum for any subarray can be written as q*k + rem where q is a quotient and rem is remainder
Thus,     
    sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2)
    sum(i, j) = (q1 - q2)k + rem1-rem2
     
We see, for sum(i, j) i.e. for sum of any subarray to be
divisible by k, the RHS should also be divisible by k.
(q1 - q2)k is obviously divisible by k, for (rem1-rem2) to 
follow the same, rem1 = rem2 where
    rem1 = Sum of subarray (0, j) % k
    rem2 = Sum of subarray (0, i-1) % k 

TC => O(N+k)
SC => O(k)

*/
