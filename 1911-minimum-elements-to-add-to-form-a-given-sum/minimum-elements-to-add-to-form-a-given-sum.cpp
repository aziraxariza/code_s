class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long curSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long reqSum = goal - curSum;
        return (abs(reqSum)+limit-1)/limit;
    }
};