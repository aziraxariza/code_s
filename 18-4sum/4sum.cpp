class Solution { // just like 3Sum w one extra for loop
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n-3; i++){ // sirf 4th last tak i chalega
            if(i > 0 && nums[i] == nums[i-1]) continue; // skip same numbers

            for(int j = i+1; j < n-2; j++){ // sirf 3rd last tak j chalega
                if(j > i+1 && nums[j] == nums[j-1]) continue; // skip same because woh alr check ho chuke

                int l = j+1;
                int r = n-1;

                while(l < r){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r]; // ll type maano sum

                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        while(l < r && nums[l+1] == nums[l]) l++; // skip same values
                        while(l < r && nums[r-1] == nums[r]) r--;
                        l++;
                        r--;
                    }
                    else if(sum < target){
                        l++; // isse bada dekho l aage badha kar
                    }
                    else{
                        r--; // zyada bada aa gaya kum karo
                    }
                }
            }
        }
        return ans;
    }
};