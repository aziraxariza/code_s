class Solution {
public:
    int reverseDegree(string s) {
        vector<int> freq(26, 0);
        freq[0] = 26;
        for(int i = 1; i < freq.size(); i++){
            freq[i] = freq[i-1] - 1; // store all alphas freq
        }

        int ans = 0; // final ans

        for(int i = 0; i < s.size(); i++){
            ans += (i+1)*(freq[s[i] - 'a']); // idx of ch in s * reversed idx
        }
        return ans;
    }
};

/*
class Solution {
public:
    int reverseDegree(string s) {
        int n = 0;
        for(int i=0;i<s.length();i++)
        {
            n+=(i+1)*(26-(s[i]-'a'));
        }
        return n;
    }
};
*/