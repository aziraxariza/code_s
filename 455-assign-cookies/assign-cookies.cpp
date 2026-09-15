class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int ptr_g = 0, ptr_s = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(ptr_g < n && ptr_s < m){

            if(g[ptr_g] <= s[ptr_s]){
                ptr_g++; // move to next kid and cookie
                ptr_s++;
            }
            else{
                ptr_s++; // sirf cookie wale ko aage badhao
            }
        }
        return ptr_g; 
    }
};