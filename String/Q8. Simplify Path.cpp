class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> st;

        for(int i = 0; i < n; i++){
            while(i < n && path[i] == '/'){
                i++;
            }

            string temp = "";
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if(temp == "." || temp.empty()) continue;

            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            } 

            else st.push(temp);
        }

        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans; // add in reverse order
            st.pop();
        }
        return (ans.empty()) ? "/" : ans;
    }
};

/*

Use Stack
TC => O(N)
SC = > O(N)

*/
