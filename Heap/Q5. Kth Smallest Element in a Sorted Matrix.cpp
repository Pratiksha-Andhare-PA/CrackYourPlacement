// Using Priority Queue/Heap

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min-heap (value, row, column)
        auto cmp = [&](pair<int,int> a,pair<int,int> b){
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };

        priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                decltype(cmp)> pq(cmp);

        for(int i = 0; i < n; i++){
            pq.push({i, 0});
        }

        for(int i = 0; i < k - 1; i++){
            auto top = pq.top();
            pq.pop();

            if(top.second + 1 < n){
                pq.push({top.first, top.second + 1});
            }
        }
        return matrix[pq.top().first][pq.top().second];
    }
};

/*

TC => O(NlogN)
SC => O(N)

*/


// Using Binary Search

class Solution {
    int CntLessEqual(vector<vector<int>> &matrix, int x){
        int n = matrix.size();
        int cnt = 0, col = n-1;
        for(int row = 0; row < n; row++){
            while(col >= 0 && matrix[row][col] > x){
                col--;
            }
            cnt += (col + 1);
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            int mid = low + (high - low) / 2;
            if(CntLessEqual(matrix, mid) < k){
                low = mid + 1;
            }
            else high = mid;
        }
        return low;
    }
};

/*

TC => O(N*log(max - min)) ~ O(N*log(mat[n-1][n-1] - mat[0][0]))
SC => O(1)

*/
