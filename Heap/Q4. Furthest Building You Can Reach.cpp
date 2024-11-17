class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < n-1; i++){
            int diff = heights[i + 1] - heights[i];
            if(diff > 0){
                minHeap.push(diff);

                if(minHeap.size() > ladders){
                    bricks -= minHeap.top();
                    minHeap.pop();
                }

                if(bricks < 0) return i;
            }
        }
        return (n - 1);
    }
};


/**

# Approaches

1) Brute Force:
Recursion => Try all possible ways

TC => O(2^N)
SC => O(N)

Drawback => TLE

2) Optimal:
Greedy + Priority Queue(minHeap)

TC => O(NlogK)
SC => O(K)

**/
