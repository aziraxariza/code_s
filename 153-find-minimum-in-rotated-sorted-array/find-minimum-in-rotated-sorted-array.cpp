class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0; // leftmost idx
        int hi = nums.size()-1;

        while(lo < hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] > nums[hi]){ // is side chhota so iss taraf jao
                lo = mid+1; // mid par hi se bada aaya so uske aage saare chhote hai 
            }
            else{
                hi = mid; // mid chhota aaya toh uss tak check kar left se
            }
        }
        return nums[lo];
    }
};