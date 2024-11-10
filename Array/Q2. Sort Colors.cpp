class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*

1) Brute Force: Sort the array(Here, for this problem not allowed, but it's one of the approach.)
TC => O(N*logN)
SC => O(1)

2) Use unordered_map to store count of 0, 1 & 2.
TC => O(N)
SC => O(3) ~ O(1)

3) Use 3 variables cnt0, cnt1, cnt2 to store frequency.
TC => O(N)
SC => O(1)

4) Use Dutch National Flag Algorithm
TC => O(N)
SC => O(1)

*/
