class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0,cnt=0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            sum += nums[i];

            if(sum == k){
                cnt++;
            }
            if(mp.find(sum - k) != mp.end()){
                cnt += mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};

/*

<================== Approaches ==================>

1) Brute Force:
Use 3 Nested loops.

TC => O(N^3)
SC => O(1)

2) Use 2 Nested loops.
TC => O(N^2)
SC => O(1)

3) Use HashMap
TC => O(N)
SC => O(N) or O(N*logN) depending on which map data structure we are using
For unordered_map => O(N) For map => O(N*logN).

*/
