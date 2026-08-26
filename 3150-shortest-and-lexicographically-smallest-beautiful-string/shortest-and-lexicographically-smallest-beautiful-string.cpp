class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int ones = 0; // 1 ke cnts

        int l = 0;
        for(int r = 0; r < s.size(); r++){
            if(s[r] == '1') ones++; // count 1

            while(ones > k){
                if(s[l] == '1'){
                    ones--; // 1 ka cnt k se zyada ho gaya
                }
                l++;
            }
            if (ones == k) {
                while (s[l] == '0') l++; // leading zeros hatao
                string cur = s.substr(l, r - l + 1); // substr l se r tak ka

                if (ans == "" || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};