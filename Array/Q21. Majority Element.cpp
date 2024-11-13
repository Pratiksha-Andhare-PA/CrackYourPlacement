class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ele;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else cnt--;
        }
        return ele;
    }
};

/*

<========= Approaches =========>

1) Brute Force:
Use 2 nested loops to count the frequency of each element.

TC => O(N^2)
SC => O(1)

2) Sort the array.

TC => O(N*logN)
SC => O(1)

3) Create an unordered map to store th frequency of each element.
Return the element with freq > (n/2).

TC => O(N)
SC => O(N)

4) Moore’s Voting Algorithm

TC => O(N)
SC => O(1)

*/
