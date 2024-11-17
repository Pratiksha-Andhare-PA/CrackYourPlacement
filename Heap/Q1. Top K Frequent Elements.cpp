class Solution {
public:
    //Bucket Sort
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //           {ele, freq}
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        //Bucket to store ele of that freq
        vector<vector<int>> bucket(n + 1);
        for(auto it : mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = n; i > 0 && ans.size() < k; i--){
            for(auto num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};

/**

1) Brute Force:
Create a map to store the frequencies of each element
Create a vector pair and store all this alements with freq.
Sort the vector pair and return top k.

TC => O(N) + O(NlogN) ~ O(NlogN)
SC => O(N)

2) Use Heap(MinHeap)/priority queue
Use map to store all ele with their freq
Push Element in PQ and pop top one if it's size is >= k and it's freq more than top ele of PQ.

TC => O(NlogK)
SC => O(N)

3) Bucket Sort
Create a bucket of size (n + 1) => At extreme the array contains only one unique ele & it's freq will be n.
Store all elements with i freq in bucket.

TC => O(N)
SC => O(N)


**/
