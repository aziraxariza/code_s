class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /* int left = 0;
        int maxi = 1;
        for(int right = left + 1; right < nums.size(); right++) */

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = (nums[n-1] - 1)*(nums[n-2] - 1);
        return ans;
    }
};