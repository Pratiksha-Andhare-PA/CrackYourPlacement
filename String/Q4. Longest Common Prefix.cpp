class Solution {
    bool isCommonPrefix(vector<string> &strs, int len){
        string prefix = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].substr(0, len) != prefix) return false;
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        int mnLen = INT_MAX;
        for(auto str : strs){
            mnLen = min(mnLen, (int)str.length());
        }

        int low = 0, high = mnLen;

        while(low < high){
            int mid = (low + high + 1) / 2;

            if(isCommonPrefix(strs, mid)){
                low = mid;
            }
            else high = mid - 1;
        }

        return strs[0].substr(0, low);
    }
};


/**

1) Brute Force:
Use 2 Nested Loops.

TC => O(N*N)
SC => O(1)

2) Binary Search:

TC => O(Slogm), 
where 
𝑆 is the total number of characters in all strings and 
𝑚 is the length of the shortest string.

SC => O(1)

**/
