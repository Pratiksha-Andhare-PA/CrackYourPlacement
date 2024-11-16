class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word="";
        for(int i=0;i<s.length();i++){
            while(s[i] != ' ' && i < s.length()){
                word += s[i];
                i++;
            }
            if (!word.empty()) {
                st.push(word);
                word = "";
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            ans += " ";
            st.pop();
        }
        if (!ans.empty()) {
            ans.pop_back(); 
        }
        return ans;
    }
};

/**

Use Stack
TC => O(N)
SC => O(N)

**/
