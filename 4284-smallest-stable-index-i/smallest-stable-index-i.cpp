class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]); // maximum value from index 0 to i

            int mini = INT_MAX; // reset minimum for the current index
            for(int j = i; j < n; j++){
                mini = min(mini, nums[j]); // minimum value from index i to n-1
            }

            if(maxi - mini <= k){
                ans = i;
                break; // this is the smallest stable index
            }
        }
        return ans;
    }
};