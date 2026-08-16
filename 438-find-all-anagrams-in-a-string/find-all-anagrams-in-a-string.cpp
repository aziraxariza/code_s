class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size()) return ans; // not possible to check

        vector<int> freq_s(26, 0); // isme hum p ke size ke window acc chars daalke check karenge 1 by 1
        vector<int> freq_p(26, 0); // saare p ke chars ki freq store

        for(int i = 0; i < p.size(); i++){
            freq_p[p[i] - 'a']++; // p ke chars stored
        }

        for(int r = 0; r < s.size(); r++){ // p.size() is our window range
            freq_s[s[r] - 'a']++;

            if(r >= p.size()){
                freq_s[s[r-p.size()] - 'a']--; // range se bada toh hatao window se
            }
            if(freq_s == freq_p) ans.push_back(r - p.size() + 1); // woh idx jisse ye anagram shuru hua
        }

        return ans;
    }
};