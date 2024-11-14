class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t idx = haystack.find(needle);

        return idx;
    }
};

/*

# Complexity Analysis

1) Brute Force:
Use 2 Nested Loops

TC => O(N^2)
SC => O(1)

2) Library Function
TC => O(N)
SC => O(1)

*/
