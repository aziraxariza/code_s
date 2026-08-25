class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]); // base case

        // case 1 when first house lo, last exclude
        vector<int> dp1(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n - 1; i++) { // sirf n-2th takk gaye
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
        }

        // case 2 jab first house exclude, last lo
        vector<int> dp2(n); // dono dp n size ke isme hum 0th idx khali rakhenge
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);

        for(int i = 3; i < n; i++) { // last tak gye i.e n-1th
            dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
        }

        return max(dp1[n - 2], dp2[n - 1]);
    }
};