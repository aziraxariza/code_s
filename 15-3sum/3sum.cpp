class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // fix one and uske aage se 2 ptr
        vector<vector<int>> ans; // final ans;
        int n = nums.size();

        sort(nums.begin(), nums.end()); // apni value ke hisab se sort ho gaye

        for(int i = 0; i < n; i++){ // ith ko fix rakhenge as 1st 
            if(i > 0 && nums[i-1] == nums[i]){
                continue; // duplicate ith ke sath wapas repeated aa sakti hai answers
            }
            int first = nums[i];
            int l = i+1;
            int r = n-1; // got our 2 pointrs

            while(l < r){
                if(first+nums[l]+nums[r] == 0){
                    ans.push_back({first, nums[l], nums[r]}); // mil gaya combo

                    while(l<r && nums[l+1]==nums[l]){
                        l++; // l ke repeated vals skip
                    }
                    while(l<r && nums[r-1]==nums[r]){
                        r--; // r ke repeated vals skip
                    }
                    l++;
                    r--; // aur check karo with this i as first
                }
                
                else if(first+nums[l]+nums[r] < 0){
                    l++; // l wale se thodi badi val dekho
                }
                else{
                    r--; // thodi chhoti dhundho r se
                }
            }
        }
        return ans;
    }
        
};