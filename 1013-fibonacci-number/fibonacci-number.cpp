class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1; // base cases

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1]+dp[i-2]; // tabulation method 1D dp
        }

        return dp[n]; 
        // space optimization ke liye do vars rakhte bas prev2 and prev1 fir current update karte rehte aur return curr karte
    }
};

/* // 1. by recursion
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        else{
            return fib(n - 1) + fib(n - 2);
        }
        return 0;
    } */

    /* // 2. memoization mein har ek i ke liye recursive call karte aur fn ke bahar 
        dp(n+1,-1)

        vector<int> dp(n+1);

        int fib(int n) {
            if(n <= 1) return n;
            if(dp[n] != -1){
                dp[i] = dp[n]; // pehle se jo value stored hai woh
            }

            return dp[n] = fib(n-1) + fib(n-2)
        } */