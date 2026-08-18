class Solution { // slow/fast 
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // slow ptr

        for(int fast = 0; fast < nums.size(); fast++){
            // agar nums[j] != 0 toh jo ith par hai usse swap and i++
            if(nums[fast] != 0){
                swap(nums[fast], nums[slow]);
                slow++; // agar nums[j] 0 hua toh i us par ruk jayega
            }
        }
    }
};