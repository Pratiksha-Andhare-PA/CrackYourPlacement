class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < nums.size(); i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else if(pq.size() >= k && pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

/**

# Approaches
1) Brute Force:
Sort the array in descending order and return (k-1)th element.
TC => O(NlogN)
SC => O(1)

2) MinHeap/Priority queue
TC => O(NlogK)
SC => O(K)

**/
