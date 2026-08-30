class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        pair<int, int> idxMinMax; // stores idx of min, max
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                idxMinMax.first = i; // actual idx store
            }

            if(nums[i] > maxi){
                maxi = nums[i];
                idxMinMax.second = i; // actual idx store
            }
        }

        int mn = idxMinMax.first;
        int mx = idxMinMax.second;

        // min ko left aur max ko right ke order me rakho
        if(mn > mx)
            swap(mn, mx); // jo idx ki value zyada woh second

        // 1. dono left se
        int left = mx + 1;

        // 2. dono right se
        int right = n - mn;

        // 3. min left se, max right se
        int both = (mn + 1) + (n - mx);

        return min({left, right, both});
    }
};