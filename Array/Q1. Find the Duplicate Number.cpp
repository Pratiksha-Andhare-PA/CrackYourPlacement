class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*
<=========== Complexity Analysis ===========>

1) Brute Force => Use 2 loops and compare every element with each of the remaining element.
TC => O(N^2)
SC => O(1)

2) Sort the array and compare with neighbour element.
TC => O(N*logN)
SC => O(1)

3) Use unordered_map to store the frequency of each element and output the one having freq >= 2.
TC => O(N)
SC => O(N)

4) Use slow & fast ptrs.
TC => O(N)
SC => O(1)

*/
