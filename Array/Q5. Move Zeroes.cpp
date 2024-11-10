class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                if(nums[idx] == 0){
                    nums[idx] = nums[i];
                    nums[i] = 0; 
                }
                idx++;
            }
        }
    }
};

/*

<============= Complexity Analysis =============>

1. Brute Force:

Create a vector and copy all non-zero elements to this vector. => O(N)

Traverse the array & update the elements with non-zero elements
and assign 0 to the remaining elements. => O(N)

TC => O(N)
SC => O(N)

2. Optimal:
Maintain an idx variable and traverse the array.

TC => O(N)
SC => O(1)

*/
