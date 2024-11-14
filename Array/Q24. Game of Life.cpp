class Solution {
    bool isValid(int i, int j, int m, int n){
        return !(i < 0 || i >= m || j < 0 || j >= n);
    }

    int cntLiveCellsAround(vector<vector<int>> &board, int x, int y){
        int m = board.size();
        int n = board[0].size();

        int cnt = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;

                int newR = i + x;
                int newC = j + y;

                if(isValid(newR, newC, m, n) && (board[newR][newC] == 1 || board[newR][newC] == -1)) cnt++;
            }
        }
        return cnt;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // -1 for live & -2 for dead 
        // to avoid the interference for calculating others

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = cntLiveCellsAround(board, i, j);
                if(board[i][j] == 1){
                    if(cnt < 2 || cnt > 3) board[i][j] = -1;
                }
                else{
                    if(cnt == 3) board[i][j] = -2;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == -2) board[i][j] = 1;
            }
        }
    }
};


/*

Complexity:
TC => O(M*N)
SC => O(1)

*/
