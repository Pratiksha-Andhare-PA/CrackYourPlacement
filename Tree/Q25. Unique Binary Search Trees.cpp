class Solution {
    long long binomialCoeff(int n, int r){
        long long ans = 1;

        // Since C(n, k) = C(n, n-k)
        if(r > n-r) r = n-r;

        // Calculate value of [n*(n-1)*---*(n-r+1)] /
        // [r*(r-1)*---*1]
        for(int i = 0; i < r; i++){
            ans *= (n-i);
            ans /= (i + 1);
        }
        return ans;
    }

public:
    int numTrees(int n) {
        long long c = binomialCoeff(2*n, n);
        return c / (n + 1);
    }
};

/**

# Approaches:

1) Brute Force:
Recursion:
No. of unique BST's = left (1 to i) * right(i+1 to n)
TC => O(2^N)
SC => O(N)

2) Dynamic Programming: Memoization
TC => O(N^2)
SC => O(N) Dp array + O(N) Recursion Stack

Tabulation:
TC => O(N^2)
SC => O(N) Only Dp array, no Recursion Stack

3) Using Catalan no. concept:
TC => O(N)
SC => O(1)

**/
