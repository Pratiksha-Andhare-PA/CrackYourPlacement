class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = 0, jumps = 0;
        while(r < n-1){
            int farthest = 0;
            for(int idx = l; idx <= r; idx++){
                farthest = max(farthest, idx + nums[idx]);
            }
            l = r + 1, 
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};

/*

1) Brute Force:
Recursion
TC => O(N^N)
SC => O(N) => Recursion call stack

2) Memoization
TC => O(N^2)
SC => O(N) + O(N) => Dp array + Recursion call stack

3) Tabulation
TC => O(N^2)
SC => O(N) => Dp array

4) Greedy
TC => O(N)
SC => O(1)

*/
