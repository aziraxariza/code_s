class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans; // final ans

        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]); // first half ka pehle
            ans.push_back(nums[i+n]); // fir second half wala
        }
        return ans;
    }
};