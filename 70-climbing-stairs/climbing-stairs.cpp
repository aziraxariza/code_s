class Solution {
public:

    int climbStairs(int n) { // tabulation se
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

/*class Solution {
public:  // MEMOIZATION
    int solve(int n, vector<int>& dp) {
        
        if(n <= 2) return n; // base

        if(dp[n] != -1) return dp[n]; // alr stored and calc return back

        dp[n] = solve(n-1, dp) + solve(n-2, dp); // warna calc karke store
        return dp[n]; 
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
    
};*/