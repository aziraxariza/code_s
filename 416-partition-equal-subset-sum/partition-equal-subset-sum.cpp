class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Odd total ko equal halves mein divide nahi kar sakte
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        // dp[i][sum] = first i elements se 'sum' bana sakte hain?
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // 0 sum hamesha possible hai: kuch bhi nahi choose karke
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {

                // Element nahi lena
                dp[i][sum] = dp[i - 1][sum];

                // Element lena
                if (nums[i - 1] <= sum) {
                    dp[i][sum] =
                        dp[i][sum] ||
                        dp[i - 1][sum - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};