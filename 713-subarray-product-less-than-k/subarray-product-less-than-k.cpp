class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int ans = 0;

        long long prdt = 1;
        int l = 0;
        for(int r = 0; r < n; r++){
            prdt *= nums[r];

            while(prdt >= k){ // since strictly less manga hai
                prdt /= nums[l];
                l++;
            }
            ans += r-l+1; // till r kitne subarr valid hai
        }
        return ans;
    }
};