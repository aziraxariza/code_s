class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int cur = nums[0];
        int ans = nums[0]; // initially

        for(int i = 1; i < nums.size(); i++){
            cur = max(nums[i], cur+nums[i]); // by itself or after adding to old cur
            ans = max(ans, cur);
        }
        return ans;
    }
};