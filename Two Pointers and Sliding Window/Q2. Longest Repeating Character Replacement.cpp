class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int left = 0, mxFreq = 0, ans = 0;

        for(int right = 0; right < n; right++){
            freq[s[right] - 'A']++;
            mxFreq = max(mxFreq, freq[s[right] - 'A']);

            // If the current window size minus maxFreq is greater than k, shrink the window
            while((right - left + 1) - mxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};


/**

#Approaches:
1) Brute Force:
Use 3 Nested Loops => To find all substrings and maintain frequency of all chars of each substrings in map
Find the replacements chars i.e. (length of that substring - max freq of the char).

TC => O(N^3)
SC => O(26) ~ O(1)

2) Use Sliding Window and 2 pointers.
Maintain frequency in map.

TC => O(N)
SC => O(26) ~ O(1)

**/
