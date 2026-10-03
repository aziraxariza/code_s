class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;

        st.push(-1); // last invalid position
        int ans = 0;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();

                if(st.empty()){
                    // ye ')' kisi '(' se match nahi hua
                    // ab naya valid substring yahin ke baad se start hoga
                    st.push(i);
                }
                else{
                    // current valid substring ki length
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};