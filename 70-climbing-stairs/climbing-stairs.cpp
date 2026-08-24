class Solution {
public:

    int climbStairs(int n) {
        if(n <= 2) return n; // base case
        vector<int> dp(n+1); // tabulation
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2]; // fibonacci series follow kr rha hai ye qosn
        }
        return dp[n];
    }
};