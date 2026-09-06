class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp; // ele -> idx store
       vector<int> ans;

       for(int i = 0; i < nums.size(); i++){
           int complement = target-nums[i]; // kitna chahiye aur is compl.

           if(mp.find(complement) != mp.end()){ // mp mein mil gaya compl.
               ans = {mp[complement], i};
           }
           mp[nums[i]] = i;
       }

       return ans;
    }
};
