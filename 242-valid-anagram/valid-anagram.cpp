class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq_s(26, 0); // for s ke chars
        vector<int> freq_t(26, 0); // for t

        for(char ch : s){
            freq_s[ch - 'a']++; // kitne baar ye ch hai s mein
        }
        for(char ch : t){
            freq_t[ch - 'a']++;
        }

        return (freq_s == freq_t); // dono mein same eles and their freq hai?
    }
};

/* O(nlogn) : 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t){
            return true; //dono sort karke same
        }
        return false;
*/