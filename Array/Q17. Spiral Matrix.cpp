class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row_start=0,row_end=m-1;
        int col_start=0,col_end=n-1;

        vector<int> ans;
        while(row_start<=row_end && col_start<=col_end){
            for(int i=col_start;i<=col_end;i++){
                ans.push_back(matrix[row_start][i]);
            }
            row_start++;
            for(int i=row_start;i<=row_end;i++){
                ans.push_back(matrix[i][col_end]);
            }
            col_end--;
            if(row_start <= row_end){
                for(int i=col_end;i>=col_start;i--){
                    ans.push_back(matrix[row_end][i]);
                }
            }
            row_end--;
            if(col_start <= col_end){
                for(int i=row_end;i>=row_start;i--){
                    ans.push_back(matrix[i][col_start]);
                }
            }
            col_start++;
        }
        return ans;
    }
};

/*
<============ Complexity Analysis ============>
TC => O(M*N)
SC => O(1) => Space for ans vector not considered.

*/
