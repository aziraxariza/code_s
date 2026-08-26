class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;

        vector<int> ans(2, -1); // ans vector

        while(lo <= hi){ // BS1 left most target eqivalen ke liye
            int mid = lo + (hi-lo)/2; //mid nikala posn

            if(nums[mid] == target){
                ans[0] = mid;
                hi = mid-1; // aur left mein khojo wapas bs ek posn peeche tak karke
            }
            else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1; // lo hi change accordingly
        }

        lo = 0; // ab right side bs to find more targets on right side
        hi = nums.size()-1;
        
        while(lo <= hi){ // first mid same aayegi dono ki.. next se updated bigger mid posn wali aayengi
            int mid = lo + (hi-lo)/2; //mid nikala posn

            if(nums[mid] == target){
                ans[1] = mid;
                lo = mid+1; // aur right mein khojo wapas bs ek posn aage se
            }
            else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1; // lo hi change accordingly
        }

        return ans;
    }
};
