class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == 0) ans = i + 1;
            
            else{
                if(mp.find(sum) != mp.end()){
                    ans = max(ans, i - mp[sum]);
                }
            
                else mp[sum] = i;
            }
        }
        
        return ans;
    }
};

/**

#Approaches
1) Brute Force:
Use 2 Nested Loops

TC => O(N^2)
SC => O(1)

2) Use HashMap
For two different indices i and j (where j > i) if the prefix sums Si and Sj are equal, 
it means that the sum of the elements between indices i+1 and j is zero. 

TC => O(N)
SC => O(N)

**/
