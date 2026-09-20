class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // fix one and uske aage se 2 ptr
        int n = nums.size();
        vector<vector<int>> ans; // final ans;

        sort(nums.begin(), nums.end()); // sort arr

        for(int i = 0; i < n; i++){// isse hum traverse karenge each ele as 1st no.
            if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate values

            int l = i+1;
            int r = n-1; // left and right ptrs

            while(l < r){

                if(nums[i]+nums[l]+nums[r] == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l+1] == nums[l]) l++; // skip duplicates
                    while(l < r && nums[r-1] == nums[r]) r--;

                    l++;
                    r--; // check for more ans
                }
                else if(nums[i]+nums[l]+nums[r] < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
        
};