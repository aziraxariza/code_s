class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0; // slow ptr
        int cnt = 0;

        for(int r = 0; r < nums.size(); r++){ // fast ptr scan arr
            if(nums[r] != val){ // same nahi hai val ke
                nums[l] = nums[r]; // toh slow posn wale posn par isko daaldo
                cnt++;
                l++; // slow aage badhao
            }
        }
        return cnt;
    }
};