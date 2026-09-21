class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // val -> idx

        for(int i = 0; i < nums.size(); i++){
            int compliment = target - nums[i];

            if(mp.count(compliment)){
                return {mp[compliment], i}; // idx of compl and current 
            }
            mp[nums[i]] = i; // add to mp
        }
        return {}; // O(n) TC and SC
    }
};
