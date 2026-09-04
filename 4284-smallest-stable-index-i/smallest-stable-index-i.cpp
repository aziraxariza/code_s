class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]); // 0 to i tak max

            int mini = INT_MAX; // har i ke liye new mini hoga 
            for(int j = i; j < n; j++){
                mini = min(mini, nums[j]); // i to n-1 tak min
            }
            if(maxi - mini <= k){
                ans = i;
                break; // smallest idx w ans
            }
        }
        return ans;
    }
};