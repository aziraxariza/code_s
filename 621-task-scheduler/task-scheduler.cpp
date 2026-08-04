class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0); // stores freq of each char in taskss;
        for(char ch : tasks){
            freq[ch - 'A']++; // freq add ki char ki 
        }

        int maxFreq = *max_element(freq.begin(), freq.end()); // max ele kya hai
        
        int cnt = 0; // to keep track kitno ki freq maxfreq se barabar hai
        for(int x : freq){
            if(x == maxFreq) cnt++; // freq equal to maxfreq
        }

        //ab formula to find total schedules
        int ans = max((int)tasks.size(), (maxFreq-1)*(n+1)+cnt); // max from total size ya gaps*blocks + cnt of maxfreq eles
        return ans;

    }
};