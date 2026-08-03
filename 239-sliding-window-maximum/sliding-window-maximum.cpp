class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*vector<int> ans;
        int n = nums.size();

        for(int i = 0; i <= n-k; i++){ // window beginning
            int lmax= INT_MIN;
            for(int j = i; j < i+k; j++){ // window size is k
                lmax= max(lmax, nums[j]); // update max in window
                if(j == i+k-1) ans.push_back(lmax); // window khatam jo max hai ab tak usko push
            }
        }
        return ans; // O(n*k) soln */

        // MONOTIC QUEUE IS SOLUTION APPROACH
        deque<int> dq; // to store idx
        vector<int> ans; 

        for(int i = 0; i < nums.size(); i++){ // traverse all idx of nums

            while(!dq.empty() && dq.front() <= i-k){ // dq mein idx out of window hai i.e lesser than window beg idx
                dq.pop_front(); // aage ke hatao 
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){ // isse peeche wale isse chhote hai toh abhi kaam nahi aayenge naa hi next window mein
                dq.pop_back(); // isliye peeche ke hatao window mein ka sabse max rahega sabse peeche
            }
            dq.push_back(i); // curr i ko dala dq mein

            if(i >= k-1)  // window completed first ke baad checks all
                ans.push_back(nums[dq.front()]); // sabse aage mein biggest hoga sab kuch hatane ke baad
        }
        return ans;
    }
};