class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int lastBad = -1; // woh idw where nums[i] < minK || nums[i] > maxK
        int lastMin = -1; // last idx jispar minK mila
        int lastMax = -1; // maxK ka last idx

        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] < minK || nums[r] > maxK) {// outside allowed range
                lastBad = r;
            }

            if(nums[r] == minK) {
                lastMin = r; // found minK
            }

            if(nums[r] == maxK) {
                lastMax = r;
            }
            // no. of valid starting points
            ans += max(0, min(lastMin, lastMax) - lastBad);
        }

        return ans;
    }
};