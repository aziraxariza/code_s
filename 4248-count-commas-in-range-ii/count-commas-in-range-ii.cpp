class Solution {
public:
    long long countCommas(long long n) {
        if(n <= 999) return 0;

        long long totalCommas = 0;
        long long start = 1000;

        while(start <= n){
            totalCommas += n - start + 1; // total commas in one power range of 1000 i.e x * 1000 aise we'll be going so ek range mein n-start[i.e the curr power of 1000.. 1000, 1000^2, 1000^3.. so on]
            start *= 1000; // update start for next range ke nums mein commas
        }
        
        return totalCommas;
    }
};