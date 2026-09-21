class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st; // eles idx

        for(int i = 2*n-1; i >= 0; i--){

            int idx = i%n; //actual from circular idx in 2n size //all comparisons w idx

            while(!st.empty() && nums[st.top()] <= nums[idx]){
                st.pop();
            }
            if(!st.empty()){
                ans[idx] = nums[st.top()]; // nge of idx 's ele
            }
            st.push(idx); 
        }
        return ans;
    }
};