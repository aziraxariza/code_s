class Solution { // nearest smaller find krna zaruri hai
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();

        stack<int> st;
        int ans = 0;

        for(int i = 0; i <= n; i++){
            int curr = (i == n ? 0 : heights[i]); // nth idx aa gaya

            while(!st.empty() && heights[st.top()] > curr){
                int h = heights[st.top()]; // ye bada so ye height
                st.pop();

                int width = (st.empty() ? i : i-st.top()-1);
                ans = max(ans, h*width);
            }

            if(i < n){
                st.push(i); // push idx
            }
        }
        return ans;
    }
};