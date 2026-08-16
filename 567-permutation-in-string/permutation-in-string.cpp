class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false; // possible hi nahi hai

        vector<int> freq_s1(26, 0);// inke chars ki freq rakho
        vector<int> freq_s2(26, 0);  // isme hum sirf range walo ki freq check karke vectors match karenge

        for(char x : s1){
            freq_s1[x - 'a']++; // s1 unchanged rahega
        }

        int l = 0;
        int k = s1.size();
        for(int r = 0; r < s2.size(); r++){ // s2 ko scan
            freq_s2[s2[r] - 'a']++; // iski freq badhayi

            if(r >= k){ // out of window gaye
                freq_s2[s2[r-k] - 'a']--;
            }
            if(freq_s1 == freq_s2) return true; // dono ke k chars same freq ke hai
        }
        return false;
    }
};