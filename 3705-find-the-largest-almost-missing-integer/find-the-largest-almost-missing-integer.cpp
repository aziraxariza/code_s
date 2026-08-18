class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int l = 0; l + k <= nums.size(); l++) {
            unordered_set<int> st;
            
            for (int r = l; r < l + k; r++) {
                st.insert(nums[r]);
            }
            for (int x : st) {
                mp[x]++;
            }
        }

        int ans = -1;

        for (auto it : mp) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};