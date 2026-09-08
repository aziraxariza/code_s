class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, mp;

        for(char c : t) {
            need[c]++;
        }

        int l = 0;
        int formed = 0;
        int required = need.size();

        int start = 0;
        int minLen = INT_MAX;

        for(int r = 0; r < s.size(); r++) {
            mp[s[r]]++;

            // required frequency of this character is satisfied
            if(need.count(s[r]) && mp[s[r]] == need[s[r]]) {
                formed++;
            }

            while(formed == required) {// valid window
                if(r - l + 1 < minLen) {// update minimum
                    minLen = r - l + 1;
                    start = l;
                }
                mp[s[l]]--;

                if(need.count(s[l]) && mp[s[l]] < need[s[l]]) {
                    formed--;
                }
                l++;
            }
        }

        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};