class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){

            int l = i + 1;
            int r = n - 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--; 
                    while(l < r && nums[l] == nums[l-1]) l++; // skip same from l side
                    while(l < r && nums[r] == nums[r+1]) r--; // skip same from r side
                }


                else if(sum < 0){
                    l++;
                } 
                else{
                    r--; // we need smaller sum so reduce r
                } 
            }
        }
        return ans;
    }
        
};