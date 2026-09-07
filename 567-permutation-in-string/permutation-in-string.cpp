class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        vector<int> freq_s1(26, 0);
        vector<int> freq_s2(26, 0);

        for(char x : s1){
            freq_s1[x-'a']++; // s1 ke store kr lo saare chars ki freq
        }

        int k = s1.size(); // s1 ka size

        for(int r = 0; r < s2.size(); r++){
            freq_s2[s2[r]-'a']++; // iski freq store

            if(r >= k){ // idx is now >= k toh peeche se ek ek hatyenge jab hum ek naya char add karenge
                freq_s2[s2[r-k]-'a']--; // k posn peeche wale ki freq reduce
            }

            if(freq_s1 == freq_s2) return true; // same chars in window as s1
        }
        return false;
    }
};