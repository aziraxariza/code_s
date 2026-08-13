class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1; // smallest divisor is 1 possible
        int hi = *max_element(nums.begin(), nums.end()); // hi ko max value li nums ki

        while(lo < hi){ // same koko eating bananas jaisa
            int mid = lo + (hi-lo)/2; // mid liya range ka beech as divisor to check

            int total = 0; // initially sum ceils 0 rakha
            for(int x : nums){
                total += (x+mid-1)/mid; // ceil liya mid ke sath
            }

            if(total <= threshold){ // threshold tak aa gaya
                hi = mid; // iss tak set karo range ki kahi isse chhota mil jaye
            }
            else{
                lo = mid+1; // mid se bade no.s se check karo
            }
        }
        return lo;
    }
};