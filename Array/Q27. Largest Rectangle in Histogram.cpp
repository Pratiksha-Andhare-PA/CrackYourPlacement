class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        int ans = 0;
        for(int i = 0; i <= n ; i++){
            while(!st.empty() && (i == n || heights[i] <= heights[st.top()])){
                int ht = heights[st.top()];
                st.pop();

                int width = (st.empty() ? i : (i - st.top() - 1));
                int currArea = (ht * width);

                ans = max(ans, currArea);
            }
            st.push(i);
        }

        return ans;
    }
};

/*

# Approaches

1) Brute force:
Use 2 Nested Loops

TC => O(N^2)
SC => O(1)

2) Use Stack

TC => O(N)
SC => O(N)

*/
