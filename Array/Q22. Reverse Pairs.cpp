class Solution {
    void Merge(vector<int> &nums, int st, int en){
        int i = st;
        int mid = (st + en)/2;
        int j = mid + 1;

        vector<int> temp;
        while(i <= mid && j <= en){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= en){
            temp.push_back(nums[j]);
            j++;
        }

        int k = 0;
        for(int idx = st; idx <= en; idx++){
            nums[idx] = temp[k];
            k++;
        }
    }

    int CntPairs(vector<int> &nums, int st, int mid, int en){
        int right = mid + 1;
        int cnt = 0;
        for(int i = st; i <= mid; i++){
            while(right <= en && (long long)nums[i] > 2LL * nums[right]){
                right++;
            }
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    int MergeSort(vector<int> &nums, int st, int en){
        int cnt = 0;
        if(st >= en) return cnt;

        int mid = (st + en)/2;

        cnt += MergeSort(nums, st, mid);
        cnt += MergeSort(nums, mid+1, en);

        cnt += CntPairs(nums, st, mid, en);

        Merge(nums, st, en);
        return cnt;
    }


public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return MergeSort(nums, 0, n-1);
    }
};


/*

<========== Approaches ==========>

1) Brute Force:
Use 2 Nested loops

TC => O(N*N)
SC => O(1)

2) Use Merge Sort

TC => O(2*NlogN)
SC => O(N)

*/

