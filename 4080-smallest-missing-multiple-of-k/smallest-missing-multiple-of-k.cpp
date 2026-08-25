class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end()); // sabko dala 
        int x = k; // initial multiple k hua
        while(st.count(x)) {
            x += k; // jab tak multiples hai tab tak x incr.
        }
        return x; // ye wala multiple nahi tha
    }
};