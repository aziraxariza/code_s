class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> st; // keep track of unique chars

        int l = 0;
        for(int r = 0; r < s.size(); r++){
            while(st.count(s[r])){
                st.erase(s[l]); // peeche se uss tak ke sare hatao 
                l++;
            }
            st.insert(s[r]); // curr char ko st mein dala

            ans = max(ans, r-l+1); // max len
        }
        return ans;
    }
};