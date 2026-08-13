class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l < r){
            int mid = l + (r-l)/2;

            if(mid % 2 == 1){ // idx is odd BUT pairs honege to woh 01 23 45 idx pairs mein honge
                mid--; //shift idx to even idx
            }

            if(nums[mid] == nums[mid+1]){ // {mid, mid+1} idx tak normal pairing chal rahi hai like 01 23 of even odd idx together pairs
                l = mid+2;
            }

            else{
                r = mid; // kuch gadbad ho gayi jiske wajah se even idx mid != mid+1 value matlab beech mein ek single hai left side par mid tak
            }

        }
        return nums[l]; // l idx jo bacha hai ab after bs us par hai single 
    }
};

