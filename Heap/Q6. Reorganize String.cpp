class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto ch : s) mp[ch]++;

        priority_queue<pair<int, char>> pq;
        for(auto x : mp){
            // If any character's frequency is greater than (n + 1) / 2, return ""
            if(x.second > (s.length() + 1) / 2) return "";
            pq.push({x.second, x.first});
        }      

        string ans = "";
        while(!pq.empty()){
            auto top1 = pq.top();
            pq.pop();
            ans += top1.second;

            auto top2 = make_pair(0, ' ');
            if(!pq.empty()){
                top2 = pq.top();
                pq.pop();
                ans += top2.second;
            }

            top1.first--;
            top2.first--;

            if(top1.first > 0) pq.push(top1);
            if(top2.first > 0) pq.push(top2);
        }
        return ans;
    }
};

/**

#Approaches

1) Brute Force:
Try all possible combinations & check for each if it's valid or not
TC => O(N! * N)
SC => O(N)

2) Using Heap/Priority Queue
TC => O(NlogK)
SC => O(K)

3) Find frequency of all chars and assign max freq chars to even poitions and remaining chars at odd.
If frequency of any of the chars is > (N + 1)/2 then return empty string.
As it's not possible to rearrange the string.

TC => O(N)
SC => O(N + 26)

**/
