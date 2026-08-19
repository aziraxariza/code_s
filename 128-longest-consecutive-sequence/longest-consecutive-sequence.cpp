class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp; // ele --> freq FOR har ek ele in asc order
        set<int> st; // unique char

        for(int x : nums){
            mp[x]++;
            st.insert(x); // sabhi ko ordered mp aur st mein dala 
        }

        int ans =  0;
        int cnt = ans;
        for(auto it : mp){ // traverse each ele of nums
            if(st.count(it.first - 1)){ // st se pata lagayenge ki uska peeche ka tha ya no
                cnt++;
            }
            else{
                cnt = 1;
            }
            ans = max(ans, cnt); // streak
        }
        return ans;
    }
};