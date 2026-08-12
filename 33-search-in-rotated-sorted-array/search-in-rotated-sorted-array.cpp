class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] == target) return mid; // mid par mil gaya

            if(nums[lo] <= nums[mid]){ // agar left side sorted hai i.e left kum hai mid se
                if(nums[lo] <= target && target < nums[mid]){ // target lo aur mid ke beech
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1; // warna right side pe hai mid ke
                }
            }
            else{ // ab humara right side sorted hai
                if(nums[hi] >= target && target > nums[mid]){ // target mid aur hi ke beech hai
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