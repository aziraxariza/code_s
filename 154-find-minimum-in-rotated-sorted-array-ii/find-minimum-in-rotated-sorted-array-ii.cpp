class Solution { // lc153 ka w duplicates wala version
public:
    int findMin(vector<int>& nums) {

        int lo = 0;
        int hi = nums.size() - 1;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > nums[hi]){
                lo = mid + 1; // minimum RIGHT mein hai
            }
            else if(nums[mid] < nums[hi]){
                hi = mid;// minimum LEFT ya mid par hai
            }
            else{
                hi--; // duplicates hain, ek duplicate hata sakte hain
            }
        }
        return nums[lo];
    }
};