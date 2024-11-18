class Solution {
    int EuclideanDist(int x, int y){
        return (x*x + y*y);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(auto pt : points){
            int x = pt[0], y = pt[1];
            int currDist = EuclideanDist(x, y);

            if(maxHeap.size() >= k){
                if(maxHeap.top().first > currDist){
                    maxHeap.pop();
                    maxHeap.push({currDist, pt});
                }
            }
            else{
                maxHeap.push({currDist, pt});
            }
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};

/**

#Approaches
1) Brute Force
Store all the distances along with the points in a vector<vector>
Sort according to the Euclidean Distances in ascending order.
Return first K among them.

TC => O(NlongN)
SC => O(N)

2) Use maxHeap/Priority Queue

TC => O(NlogK)
SC => O(K)

**/
