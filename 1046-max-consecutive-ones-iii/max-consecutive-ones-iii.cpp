class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0;
        int zeros = 0; // cnt zero to keep track
        int ans = 0;

        for(int r = 0; r < nums.size(); r++) {

            if(nums[r] == 0) zeros++; // cnt zeros

            while(zeros > k) { // jaise hi k se hue 
                if(nums[l] == 0){ // preceeding 0s ko hatao jo k+1th  0 zero tak hai
                    zeros--; 
                }
                l++; // jab tak k zeros nahi hat te 
            }
            ans = max(ans, r - l + 1); // max streak
        }
        return ans;
    }
};