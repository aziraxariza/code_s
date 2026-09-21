class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0]; // abhi tak ka max prdt
        int curMin = nums[0]; // abhi tak ka min prdt

        int ans = nums[0]; // initially ans

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 1){ // negative val ke liye max aur min swap 
                swap(curMax, curMin); 
            }
            curMax = max(nums[i], curMax*nums[i]); // by itself or after *ing
            curMin = min(nums[i], curMin*nums[i]);

            ans = max(ans, curMax);
        }
        return ans;
    }
};