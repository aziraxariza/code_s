class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string chk = "";
        for(int i = 0; i < n; i++){
            if(!isalnum(s[i])) continue;
            else chk += tolower(s[i]);
        }

        int l = 0;
        int r = chk.size() - 1;
        while(l < r){
            if(chk[l] == chk[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};
