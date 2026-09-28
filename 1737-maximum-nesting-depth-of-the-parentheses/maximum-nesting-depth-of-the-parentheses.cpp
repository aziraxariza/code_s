class Solution {
public:
    int maxDepth(string s) {
        stack<char> st; // store '('

        int ans = 0;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                ans = max(ans, (int)st.size());
                st.pop();
            }
            else{
                continue;
            }
        }
        return ans;
    }
};