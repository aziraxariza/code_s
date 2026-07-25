class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;

        while (n > 0) {
            int rem = n % 10;      // extract last digit
            nums.push_back(rem);   // store every digit
            n /= 10;               // remove last digit
        }

        sort(nums.begin(), nums.end());

        int len = nums.size();
        return nums[len - 1] * nums[len - 2];
    }
};