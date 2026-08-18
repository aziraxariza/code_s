class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; // unique chars rahenge

        int ans = 0;
        int cnt = 0;
        int left = 0; // s ke chars ko pakadke rakhne ke liye

        for(char ch : s) {
            while(st.count(ch)) { // agar ye already hai st mein
                st.erase(s[left]); // jab tak hai tab tak sare left ke hatao
                left++;// next left par lao
                cnt--; // cnt decrease jitne hate unke
            }

            st.insert(ch); // insert into set 
            cnt++;
            ans = max(ans, cnt); // max cnt is ans
        }
        return ans;
    }
};