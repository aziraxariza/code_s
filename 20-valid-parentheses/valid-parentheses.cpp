class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // for opening brackets

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch); // push to st
            }
            else if(!st.empty() && 
                    (ch == ')' && st.top() == '(' || 
                     ch == '}' && st.top() == '{' || 
                     ch == ']' && st.top() == '[')){
                st.pop(); // remove matching
            }
            else{
                return false; // closing aaya but matching opening nahi hai
            }
        }
        return st.empty(); // all done or not
    }
};