class Solution {
    bool backTrack(vector<vector<char>> &board, int i, int j, int k, string word){
        int m = board.size();
        int n = board[0].size();

        if(k == word.length()) return true;

        if(i < 0 || i >= m || j < 0 || j >= n) return false;

        if(board[i][j] != word[k]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool isFound = backTrack(board, i+1, j, k+1, word) || 
                        backTrack(board, i, j+1, k+1, word) || 
                        backTrack(board, i-1, j, k+1, word) || 
                        backTrack(board, i, j-1, k+1, word);
                        
        board[i][j] = temp;

        return isFound;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backTrack(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};

/*

<===== Complexity Analysis =====>

TC => O(M*N*4^K)
SC => O(K) => Recursion Call Stack

*/
