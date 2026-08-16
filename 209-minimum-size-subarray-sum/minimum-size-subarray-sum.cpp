class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int ans = INT_MAX;
        int sum = 0;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r]; // iskko add kiya

            while(sum >= target){ // ab jab sum zyada ya barabar aa gaya target se
                ans = min(ans, r-l+1); // length leli
                sum -= nums[l]; // ab peeche se nikalna start karo jab tak kum na ban jaye target se
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans; // agar ans abhi bhi inf hai toh 0 warna min length of valid subarr
    }
};