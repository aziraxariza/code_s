class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]); // base cases

        vector<int> dp(n); // saare house tak ka max chori val store karega
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]); // comparing peeche idx tak bada tha ya isko second last ke sath add karke badi chori hui
        }

        return dp[n-1];
    }
};

/*int f(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0)// sirf pehla house bacha
            return nums[0];

        if (ind < 0)// koi house nahi bacha
            return 0;

        if (dp[ind] != -1) // pehle se calculate hai
            return dp[ind];

        int pick = nums[ind] + f(ind - 2, nums, dp); // current house rob karo
        int notPick = f(ind - 1, nums, dp);// current house skip karo

        return dp[ind] = max(pick, notPick); // best choice store karo --> i tak ye hai amt
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);// memoization array
        return f(n - 1, nums, dp);// last house se start
    }
*/