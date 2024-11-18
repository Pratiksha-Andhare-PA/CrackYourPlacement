class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        for(int i = 0; i < n; i++){
            while(!ans.empty() && ans.back() > nums[i] && (ans.size() + (n - i)) > k){
                ans.pop_back();
            }
            if(ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }
};

/**

#Approaches
1) Brute Force
Find all possible subsequences of size K and return the smallest one by sorting

TC => O(2^N * N)
SC => O(2^N)

2) Use Stack / Priority Queue

TC => O(N)
SC => O(K)

**/
