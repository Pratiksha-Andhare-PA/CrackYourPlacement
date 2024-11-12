class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i = 0; i < n; i++){
            // already visited the element
            if(nums[abs(nums[i]) - 1] < 0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return ans;
    }
};

/*

<============== Approaches ==============>

1) Brute Force:
Use 2 loops and check for duplicate elements.
TC => O(N*N)
SC => O(1)

2) Sort the array & check for duplicates for adjacent elements.
TC => O(N*logN)
SC => O(1)

3) Maintain frequency of each element in a vector.
Print the elements having frequency 2 (or) more than 1.
TC => O(2N)
SC => O(N)

4) Traverse the array and change the sign of the elements with idx nums[abs(nums[i])-1]
If not visited & if the element is already -ve means it's visited twice, print it.
TC => O(N)
SC => O(1)

*/
