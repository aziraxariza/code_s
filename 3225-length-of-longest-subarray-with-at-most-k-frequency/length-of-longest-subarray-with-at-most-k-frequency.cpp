class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // element --> frequency
        int l = 0;
        int ans = 0;

        for(int r = 0; r < nums.size(); r++){
            mp[nums[r]]++; // current window mein freq increase

            while(mp[nums[r]] > k){ // window invalid hai
                mp[nums[l]]--; // left wale element ko hatao
                l++; // window ko l+1 se strat kiya
            }

            ans = max(ans, r - l + 1); // warna valid window ka max
        }
        return ans;
    }
};