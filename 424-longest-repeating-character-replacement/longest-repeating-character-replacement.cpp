class Solution {
public:
    int characterReplacement(string s, int k){ // k is kitne replace kr skte

        vector<int> freq(26, 0); // valid window ke chars ki freq
        int l = 0; 
        int maxFreq = 0; // max freq kitni hai in window
        int ans = 0;

        for(int r = 0; r < s.size(); r++){
            freq[s[r]-'A']++; // iss char ki freq update
            maxFreq = max(maxFreq, freq[s[r]-'A']); // update max freq

            while(r-l+1 - maxFreq > k){ // jab tak window len mein <= k diff hai ok warna size change karo peeche 
            // we are ignoring sirf k chars at once **
                freq[s[l]-'A']--; // peeche se hatao
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};