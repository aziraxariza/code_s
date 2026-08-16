class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index * since index chahiye ans mein so don't sort

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // kitna aur difference chahiye

            if (mp.find(complement) != mp.end()) { // kya difference hai present in mp
                return {mp[complement], i}; // return idx of both
            }
            mp[nums[i]] = i; // idhar hum sath mein daalre hai mp mein
        }
        return {};
    }
};
