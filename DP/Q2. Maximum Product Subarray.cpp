class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cp=1;

        int mx1 = INT_MIN;
        int mx2 = INT_MIN;

        for(int i=0;i<n;i++){
            cp *= nums[i];
            mx1 = max(mx1,cp);
            if(cp == 0)
                cp = 1;
        }
        
        cp = 1;
        for(int i=n-1;i>=0;i--){
            cp *= nums[i];
            mx2 = max(mx2,cp);
            if(cp == 0)
                cp = 1;
        }
        return max(mx1,mx2);
    }
};
