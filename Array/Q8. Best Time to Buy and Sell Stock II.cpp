class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0){
                    curr[buy] = max(prev[0], prev[1] - prices[idx]);
                }
                if(buy == 1){
                    curr[buy] = max(prev[1], prev[0] + prices[idx]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};

/*

<================ Approaches ================>

1) Brute Force:
Every element has 2 choices to pick or not to pick.
Maintain a variable buy to check if we're holding any stock or free to buy new one.

TC => O(2^N)
SC => O(N) => Recursion Stack space

2) Memoization 

TC => O(N*2) 
SC => O(N*2) + O(N) => (2D dp + Recursion Stack Space)

3) Tabulation

TC => O(N*2)
SC => O(N*2) => (2D dp)

4) Space Optimization

TC => O(N*2)
SC => O(1)

*/
