class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1); // stores is step *tak* ka min cost kitna laga
        dp[0] = 0;
        dp[1] = 0; // ye dono direct laang sakte hai

        for(int i = 2; i <= n; i++){
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]); // jis par chadhe uska cost count karna padega
        }
        return dp[n];
    }
};

/*
int solve(vector<int>& dp, vector<int>& cost, int n){
    if(n <= 1) return 0;

    if(dp[n] != -1) return dp[n];

    dp[n] = min(solve(dp[n-1]+cost[n-1]), solve(dp[n-2]+cost[n-2]));
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n+1, -1);
    return solve(dp, cost, n);
}
*/