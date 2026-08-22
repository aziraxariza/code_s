class Solution {
public:
    bool checkDivisibility(int n) {
        int dSum = 0;
        int dPrdt = 1;
        int chk = n; // store n for final divisibility check
        while(n > 0){
            int rem = n%10;
            dSum += rem;
            dPrdt *= rem;
            n = n/10;
        }

        int d = dSum + dPrdt;
        if(chk % d == 0) return true;
        return false;
    }
};