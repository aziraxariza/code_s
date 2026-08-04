class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] != nums[i] + 1) { // gap mila
                for (int x = nums[i] + 1; x < nums[i + 1]; x++)
                    ans.push_back(x); // sabhi missing ko ans mein dalo
            }
        }
        return ans;
    }
};