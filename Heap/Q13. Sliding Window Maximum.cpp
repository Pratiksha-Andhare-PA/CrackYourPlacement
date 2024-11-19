class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < n; i++){
            // Remove indices of elements not in the current window
            if(!dq.empty() && dq.front() < i - k + 1){
                dq.pop_front();
            }

            // Remove indices of smaller elements from the back
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Append the maximum of the current window to the result
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

/**

#Approaches
1) Brute Force:
Try all possible subarrays of size K
TC => O(N*K)
SC => O(1)

2) Optimal: Using Deque

TC => O(N)
SC => O(K)

**/
