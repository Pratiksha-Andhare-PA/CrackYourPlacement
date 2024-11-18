class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int fuel = startFuel, i = 0, stops = 0;

        int n = stations.size();
        while(fuel < target){
            while(i < n && fuel >= stations[i][0]){
                maxHeap.push(stations[i][1]);
                i++;
            }

            // If no more stations are reachable and target isn't reached
            if(maxHeap.empty()) return -1;

            // Refuel with the largest amount
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        
        return stops;
    }
};

/**

#Approaches
1) Brute Force:
Try all possible ways.
There will be 2 options for each stations Refuel or not.

TC => O(2^N)
SC => O(N)

2) MaxHeap/Priority Queue
Refuel with the maximum first to reduce the number of stations.

TC => O(NlogN)
SC => O(N)

**/
