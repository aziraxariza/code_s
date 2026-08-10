class Solution {
public:
    char findTheDifference(string s, string t) {

        int hash_s[26] = {0};
        int hash_t[26] = {0};

        for(int i = 0; i < s.size(); i++) { // s ke sabhi ki frq
            hash_s[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++) { // t ke sabhi ki freq
            hash_t[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) { // agar dono ki freq same na hui toh return char
            if(hash_t[i] != hash_s[i]) {
                return 'a' + i;
            }
        }

        return ' ';
    }
};