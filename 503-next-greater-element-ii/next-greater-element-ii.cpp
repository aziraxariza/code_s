class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n; // circular index

            while(!st.empty() && st.top() <= nums[idx])
                st.pop(); // remove smaller/equal elements

            if(i < n) { // store answer only for original array
                if(!st.empty())
                    ans[idx] = st.top();
            }
            st.push(nums[idx]);// current ab hai candidate for left elements
        }
        return ans;
    }
};