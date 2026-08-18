class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mp; // val --> freq 
        for(int x : nums){
            mp[x]++;
            if(mp[x] > n/2) ans = x;
        }
        return ans;
    }
};
