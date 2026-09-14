class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // opening brackets ke liye

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false; // koi opening hai hi nahi in st for this closing bracket

                else if(ch == ')' && st.top() == '(' || 
                        ch == '}' && st.top() == '{' ||
                        ch == ']' && st.top() == '['){
                            st.pop(); // remove agr counter bracket top par hai
                }
                else{
                    return false; // mismatched combo
                }
            } 
        }
        return st.empty(); 
    }
};