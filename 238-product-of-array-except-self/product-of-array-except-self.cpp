class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); // final ans

        for(int i = 1; i < n; i++){ // prefix way
            ans[i] = ans[i-1] * nums[i-1]; //peeche wale tak ka ans * peeche wale ki val
        }

        int suffix = 1;
        for(int j = n-1; j >= 0; j--){ // suffix way
            ans[j] *= suffix;
            suffix *= nums[j]; // update suffix by * last val
        }
        return ans;
    }
};