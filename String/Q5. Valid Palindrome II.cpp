class Solution {
    bool isPal(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int low = 0, high = s.length() - 1;
        while(low  < high){
            if(s[low] == s[high]) low++, high--;
            else return isPal(s, low, high - 1) || isPal(s, low + 1, high);
        }
        return true;
    }
};

/*

# Approaches

1) Brute Force
Check if the string can become palindrome by deleting each character once

TC => O(N^2)
SC => O(1)

2) Optimal
TC => O(N) => (N/2 + 2*N ) ~ O(N)
SC => O(1)

*/
