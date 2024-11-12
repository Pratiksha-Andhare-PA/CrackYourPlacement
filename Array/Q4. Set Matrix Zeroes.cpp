class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // 0th ele of 0th row
        int col0 = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else col0 = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

/*
<========== Approaches ==========>

1) Brute Force:
Traverse through matrix and mark the value of respective row and col of each element having value 0 as -1.
Again traverse the matrix and replace all -1 with 0.

TC => O((M*N)*(M+N)) + O(M*N)
SC => O(1)

Drawback => Fails when the matrix contains value -1.

2) Create 2 vectors(row & col).
Traverse the matrix and mark the elements at the idx having value 0 as 1.
Traverse the matrix again and check for each element if row[i] (or) col[j] is 1 or not. 
If yes, then mark it as 0.

TC => O(2*M*N)
SC => O(M+N)

3) Use 0th col and 0th row of matrix instead of creating new vectors to optimize space.
Use extra variable col0.

TC => O(2*M*N)
SC => O(1)

*/
