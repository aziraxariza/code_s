class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // for all temps

        stack<int> st; // mono stack for idx 
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop(); // remove from stack
            }
            if(!st.empty()){
                ans[i] = st.top()-i; // dist
            }

            st.push(i); // push idx to st
        }
        return ans;
    }
};