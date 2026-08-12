class Solution {
public:
    bool search(vector<int>& nums, int target) { // ye diff hai lc 33 se ki isme distinct vals nhi hai
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] == target) return true; // mid par mil gaya

            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){ // duplicates ki wajah se side decide nahi kar sakte
                lo++;
                hi--;
            }
            else if(nums[lo] <= nums[mid]){ // left side sorted hai
                if(nums[lo] <= target && target < nums[mid]){
                    hi = mid - 1; // target left sorted part mein hai
                }
                else{
                    lo = mid + 1; // target right mein hai
                }
            }
            else{ // right side sorted hai
                if(nums[mid] < target && target <= nums[hi]){
                    lo = mid + 1; // target right sorted part mein hai
                }
                else{
                    hi = mid - 1; // target left mein hai
                }
            }
        }
        return false;
    }
};