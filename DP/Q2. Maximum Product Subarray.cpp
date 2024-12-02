class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int pre = 1, suff = 1;

        for(int i = 0; i < n; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre *= nums[i];
            suff *= nums[n - i - 1];

            ans = max(ans, max(pre, suff));
        }

        return ans;
    }
};

/**

# Approaches:

1) Brute Force: 2 Nested loops
TC => O(N^2)
SC => O(1)

2) Optimal: 
3 cases: a) All +ve no.
         b) Even -ve no.
         c) Odd -ve no.

    In case a & b, the ans will be the product of the entire array
    In case of c, remove 1 -ve no. such that will get the maximum product.
    To handle this, use prefix and suffix products.
    Also, handle the case of having num 0. Reset pre/suff to 1 accordingly.

TC => O(N)
SC => O(1)

**/
