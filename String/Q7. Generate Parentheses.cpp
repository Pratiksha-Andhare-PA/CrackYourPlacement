class Solution {
    void backTrack(vector<string> &ans, string output, int openCnt, int closedCnt, int n){
        if(output.length() == 2*n){
            ans.push_back(output);
            return;
        }

        if(openCnt < n){
            output.push_back('(');
            backTrack(ans, output, openCnt + 1, closedCnt, n);
            output.pop_back();
        }

        if(closedCnt < openCnt){
            output.push_back(')');
            backTrack(ans, output, openCnt, closedCnt + 1, n);
            output.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);
        return ans;
    }
};


/*

#Backtracking

TC => 
The number of valid parentheses combinations corresponds to the Catalan number Cn => (1/ n+1)(2n Cn)
This grows asymptotically as O(4^n/sqrt(n))

SC => 
Recursion Stack:

The depth of the recursion is 2n, corresponding to the length of the string being built.
Thus, the recursion stack requires O(2n) = O(n)

O(2n)=O(n) space.
Result Storage:

The number of valid combinations is Cn and each combination is a string of length 2N.
The total space to store the results is O(n.Cn)

Thus, the space complexity is: O(n.Cn)

*/
