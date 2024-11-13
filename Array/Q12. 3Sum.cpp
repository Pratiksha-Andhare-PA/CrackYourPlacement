class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};

/*

<============== Approaches ==============>

1) Brute Force:
Use 3 loops, take sums and check the sum is target or not.

TC => O(N^3)
SC => O(1)

2) 
a. First, we will declare a set data structure as we want unique triplets.
b. Then we will use the first loop(say i) that will run from 0 to n-1.
c. Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
d. Before the second loop, we will declare another HashSet to store the array elements as we intend to search for the third element using this HashSet.
e. Inside the second loop, we will calculate the value of the third element i.e. -(arr[i]+arr[j]).
f. If the third element exists in the HashSet, we will sort these 3 values i.e. arr[i], arr[j], and the third element, and insert it in the set data structure declared in step 1.
g. After that, we will insert the jth element i.e. arr[j] in the HashSet as we only want to insert those array elements that are in between indices i and j.
h. Finally, we will return a list of triplets stored in the set data structure.

TC => O(N2 * log(no. of unique triplets))
SC => O(2 * no. of the unique triplets) + O(N)

3) Sort the array.
Traverse the array and use 2 ptrs.

TC => O(N*logN) + O(N*N)
SC => O(1)

*/
