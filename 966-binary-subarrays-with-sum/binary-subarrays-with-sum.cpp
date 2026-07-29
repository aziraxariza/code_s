class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int n = nums.size();
        int l = 0;
        int sm = 0;
        int cnt = 0;

        for(int r = 0; r < n; r++) {
            sm += nums[r]; // window expand

            while(sm > goal) {
                sm -= nums[l]; // left element remove
                l++; // window shrink
            }

            cnt += r - l + 1; // valid subarrays ending at r
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1); // exactly goal
    }
};