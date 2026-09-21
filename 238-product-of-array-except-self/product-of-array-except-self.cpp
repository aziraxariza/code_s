class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, 1); // final ans hoga

        // left side se i.e prefix 
        for(int i = 1; i < n; i++){
            ans[i] = nums[i-1] * ans[i-1]; // last val * peeche tak ka ans 
        }

        int suffix = 1; // right side se peeche
        for(int i = n-1; i >= 0; i--){
            ans[i] *= suffix; 
            suffix *= nums[i]; // update suffix nums[i] ki val se
        }

        return ans;
    }
};