class Solution {
public:
    int minOperations(int k) { // initially nums[] = [1]
        int ans = k;

        for(int a = 0; a < k; a++){
            int x = 1 + a; // value after incr. 1 by a 
            int b = (k + x - 1)/x - 1; // ceil(k/x) - 1
            ans = min(ans, a + b);
        }
        return ans;
    }
};