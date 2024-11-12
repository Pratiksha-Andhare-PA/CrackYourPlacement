class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = INT_MIN;
        int i = 0, j = n-1;
        while(i < j){
            int currArea = (j - i) * min(height[i], height[j]);
            if(currArea > ans){
                ans = currArea;
            }
            
            else{
                if(height[i] < height[j]) i++;
                else j--;
            }
        }
        return ans;
    }
};

/*

<================== Approaches ==================>

1) Brute Force:
Use 2 loops and find area of each container formed using the 2 pts.
Print the maximum one.

TC => O(N*N)
SC => O(1)

2) Use 2 ptr approach.
Calculate the area of the container for current pts.
If it's maximum till that pt., then update the ans & increment both the ptrs.
If not, then increment one of the ptr, side having smaller height.

TC => O(N)
SC => O(1)

*/
