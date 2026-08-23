class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); // sab abhi 1 hai

        for(int i = 1; i < n; i++){ // prefix product
            ans[i] = ans[i-1] * nums[i-1]; // khudko chodke peeche tak ke prdt aur nums mein khudke peeche ka kyuki peeche wale mein woh misisng hai
        }
        
        int suffix = 1; // suffix prdt
        for(int j = n-1; j >= 0; j--){
            ans[j] *= suffix; // isko first suffix se multiply
            suffix *= nums[j]; // make curr right as nums[j]
        }

        return ans;
    }
};