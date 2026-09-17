class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int cur = nums[0]; // current subarray ka sum
        int ans = nums[0];  // ab tak ka maximum subarray sum

        for(int r = 1; r < nums.size(); r++) {
            cur = max(nums[r], cur + nums[r]);
            ans = max(ans, cur);  // maximum answer update karo
        }

        return ans; // maximum subarray sum
    }
};