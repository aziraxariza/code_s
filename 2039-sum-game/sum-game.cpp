class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2; //midpnt

        int sum1 = 0, sum2 = 0; // 1st aur 2nd half ka sum
        int q1 = 0, q2 = 0; // 1st aur 2nd half mein ? ke cnts

        for (int i = 0; i < half; i++) {
            if (num[i] == '?') q1++;
            else sum1 += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?') q2++; 
            else sum2 += num[i] - '0';
        }

        int diff = sum1 - sum2;
        int qdiff = q2 - q1;

        if (qdiff % 2 == 0 && diff == 9 * (qdiff / 2)){
            return false; // bob sums equal krlega
        }
        return true;
    }
};