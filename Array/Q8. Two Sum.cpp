class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

/*

<============ Approaches ============>

1) Brute Force:
Use 2 loops to traverse the array.
Check which 2 elements adds up to target & return the corresponding indices.
TC => O(N*N)
SC => O(1)

2) Use HashMap:
Store the elements along with indices while traversing and check if (target - curr element) exists in the map if yes then return its indices.
TC => O(N)
SC => O(N)

*/
