class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // important for subarrays starting at index 0
        
        int sum = 0, count = 0;
        
        for(int num : nums) {
            sum += num;
            
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            
            mp[sum]++;
        }
        
        return count;
    }
};