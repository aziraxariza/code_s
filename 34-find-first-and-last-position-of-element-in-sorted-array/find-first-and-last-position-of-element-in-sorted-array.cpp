class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;

        vector<int> ans = {-1, -1}; // final posns of target in nums

        while(lo <= hi){ // BS1 leftmost target ki index
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target){
                ans[0] = mid; // left most ka index ye set kiya
                hi = mid-1; // isse chhote idx par target dhundho
            }
            else if(nums[mid] < target){
                lo = mid+1; // mid ke aage dhundho 
            }
            else{
                hi = mid-1; // mid se chhota hai
            }
        }

        lo = 0;
        hi = nums.size() - 1; //BS2 ke liye wapas redeclare

        while(lo <= hi){ // BS2 rightmost target ki index
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target){
                ans[1] = mid; // right most ka index ye set kiya
                lo = mid+1; // isse bade idx par target dhundho
            }
            else if(nums[mid] < target){
                lo = mid+1; // mid ke aage dhundho 
            }
            else{
                hi = mid-1; // mid se chhota hai
            }
        }
        return ans;
    }
};
