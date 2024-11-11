class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPrice = INT_MAX, mxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            mnPrice = min(mnPrice, prices[i]);
            mxProfit = max(mxProfit, (prices[i] - mnPrice));
        }
        return mxProfit;
    }
};

/* 

<=================== Approaches ===================>

1) Brute Force Approach:
Use 2 loops to traverse the array
i: 0 => n-1 & j : i+1 => n
Check if jth price is greater than ith then update the ans by (price[j] - price[i]).

TC => O(N*N)
SC => O(1)
causes TLE

2) Keep track of minPrice and maxProfit.
TC => O(N)
SC => O(1)

*/
