class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target) return mid; // mil gaya return idx

            if(nums[lo] <= nums[mid]){ // left half sorted
                if(nums[lo] <= target && target < nums[mid]){// target left sorted range mein hai
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }

            else{ 
                if(nums[mid] < target && target <= nums[hi]){// target right sorted range mein hai
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