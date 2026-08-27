class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target) return mid; // mil gaya return idx

            if(nums[lo] <= nums[mid]){ // target left sorted range mein hai
                if(nums[lo] <= target && target < nums[mid]){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }

            else{ // target right sorted range mein hai
                if(nums[mid] < target && target <= nums[hi]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};