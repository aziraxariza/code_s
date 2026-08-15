class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) { // scan karenge array * j apne aap badhta chalega
            if (nums[i] != 0) { // zero nahi hai
                swap(nums[i], nums[j]); // toh swap with slow ptr value
                j++; // slow aage badhaya
            } 
        }
    }
};