class Solution {
public:

    int totalCommas(int n){ // fn to calc commas in ith num

        int cnt = 0; // total digits
        int ans = 0; // final ans

        while(n > 0){
            int rem = n%10; // get digit from back
            cnt++; // kitne digis hue
            n /= 10;
        }

        if(cnt%3 == 0){
            ans = (cnt/3) -1; // eg. 200,000 sirf ek comma
        }
        else{
            ans = cnt/3; 
        }
        return ans;
    }

    int countCommas(int n) {
        if(n/1000 < 1) return 0; // 3 digis hai at max in n

        int commas = 0;
        for(int i = 1000; i <= n; i++){
            commas += totalCommas(i);
        }

        return commas;
    }
};