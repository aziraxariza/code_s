class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st; // sabhi nums ke no.s ko set mein dalenge

        for(int x : nums){
            st.insert(x); 
        }

        int ans =  0;
        int cnt = ans;
        for(int x : st){ // traverse each ele of nums in st
            if(st.count(x - 1)){ // st se pata lagayenge ki uska peeche ka tha ya no
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

/*  extra ans
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
        return ans;*/