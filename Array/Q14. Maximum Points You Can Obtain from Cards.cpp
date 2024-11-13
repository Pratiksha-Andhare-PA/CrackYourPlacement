class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int leftSum = 0;
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }

        int mxScore = leftSum;
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[n - i - 1] - cardPoints[k - i- 1];
            mxScore = max(mxScore, leftSum);
        }

        return mxScore;
    }
};

/*

<=============== Approaches ===============>

1) Brute Force:
Use Recursion
TC => O(2^k)
SC => O(k)
Problem => TLE

2) Memoization
TC => O(N*k)
SC => O(N*k) + O(k)
Problem => MLE

3) Calculate the sum of the first k cards from the beginning.
Initialize the maximum score as taking all k cards from the beginning.
Gradually replace cards from the beginning with cards from the end.
Calculate the maximum score.

TC = >O(k)
SC => O(1)

*/
