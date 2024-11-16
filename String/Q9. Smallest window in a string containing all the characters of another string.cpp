class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // If s2 is longer than s1, no window can be found
        if (n2 > n1) return "-1";
        
        unordered_map<char, int> mp2, mp1;
        
        // Count the frequencies of characters in s2
        for (char ch : s2) {
            mp2[ch]++;
        }
        
        int i = 0, j = 0;
        int mnLen = INT_MAX;
        pair<int, int> indices;
        int currChars = 0; // Counts how many characters from s2 are in the window
        
        while (j < n1) {
            // Add current character to the window
            if (mp2.find(s1[j]) != mp2.end()) {
                mp1[s1[j]]++;
                // If this character satisfies the count needed in s2, increase current match
                if (mp1[s1[j]] == mp2[s1[j]]) {
                    currChars++;
                }
            }
            
            // Shrink the window if all required characters are matched
            while (currChars == mp2.size()) {
                // Update the answer if the current window is smaller
                if (mnLen > (j - i + 1)) {
                    mnLen = j - i + 1;
                    indices = {i, j};
                }
                
                // Remove the leftmost character from the window
                if (mp1.find(s1[i]) != mp1.end()) {
                    mp1[s1[i]]--;
                    if (mp1[s1[i]] < mp2[s1[i]]) {
                        currChars--;
                    }
                }
                i++;
            }
            j++;
        }
        
        // If no window is found, return -1
        if (mnLen == INT_MAX) return "-1";
        
        // Return the substring corresponding to the smallest window
        return s1.substr(indices.first, mnLen);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        cout << obj.smallestWindow(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

/**

1) Brute Force:
Find all the substrings of first string and check for each substring 
if it contains all the characters of the 2nd string.

TC => O(N^3) => O(N^2) for all finding substrings & O(N) for checking if having all the characters
SC => O(N) => For using unordered map

2) Use Sliding Window approach:
2 ptrs & 2 maps

TC => O(N)
SC => O(1) => As at max there can be 26 chars
Initialize map(26)

**/

