class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        //       {efficiency, quality}
        vector<pair<double, int>> workers;
        for(int i = 0; i < n; i++){
            double efficiency = ((double)wage[i] / quality[i]);
            workers.push_back({efficiency, quality[i]});
        }

        sort(workers.begin(), workers.end());

        int totalQuality = 0;
        double mnCost = DBL_MAX;

        priority_queue<int> maxHeap;
        for(auto worker : workers){
            double efficiency = worker.first;
            int qlty = worker.second;

            // Add the current worker's quality to the heap
            maxHeap.push(qlty);
            totalQuality += qlty;

            // If the heap exceeds size k, remove the largest quality
            if(maxHeap.size() > k){
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }

            // If the heap size is exactly k, calculate the cost
            if(maxHeap.size() == k){
                double cost = totalQuality * efficiency;
                mnCost = min(mnCost, cost);
            }
        }
        return mnCost;
    }
};

/**

TC => O(NlogN) + O(NlogK) ~ O(NlogN)
SC => O(N + K)

**/
