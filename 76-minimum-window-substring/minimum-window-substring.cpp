class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need;
        map<char, int> have;

        for(char c : t){
            need[c]++;
        }

        int l = 0;
        int formed = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            have[c]++;

            if(need.count(c) && have[c] == need[c]){ // required frequency complete hui
                formed++;
            }

            while(formed == need.size()){ // window valid
                if(r - l + 1 < minLen){ // update answer
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                have[leftChar]--;

                if(need.count(leftChar) && // invalid ho gayi window
                   have[leftChar] < need[leftChar]){
                    formed--;
                }

                l++;
            }
        }

        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start, minLen);
    }
};