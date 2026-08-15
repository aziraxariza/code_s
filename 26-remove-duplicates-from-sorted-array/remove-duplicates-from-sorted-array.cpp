class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int j = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[j]){ // dono alag hai toh
                j++; // j badhao
                nums[j] = nums[i]; // j ki posn par ith daal do 
            }
        }

        return j + 1; // j is idx so idx+1 eles unique hai
    }
};