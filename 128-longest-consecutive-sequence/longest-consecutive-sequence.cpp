class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 1;
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;          
            }
            else if (nums[i] == nums[i - 1] + 1) {
                cnt++;                  
            }
            else {
                maxi = max(maxi, cnt);  // *** eg. [1,2,10,11,12,13]
                cnt = 1;                
            }
        }
        return max(maxi, cnt);
    }
};