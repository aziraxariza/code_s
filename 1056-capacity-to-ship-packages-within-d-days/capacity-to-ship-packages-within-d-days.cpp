class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()); // so that mid capacity > max ele 
        int hi = accumulate(weights.begin(), weights.end(), 0); // imagine sirf ek din ho

        while(lo < hi){
            int mid = lo + (hi-lo)/2;// middle capacity kitna weight le sakte ek din

            int total = 0; // total weights of bags
            int daysUsed = 1; // kitne din lage

            for(int wei : weights){
                if(total + wei> mid){
                    daysUsed++; // new day kyuki new total zyada aa raha hai capacity se
                    total = 0; // for next day
                }
                total += wei; // add wei to this day
            }
            if(daysUsed <= days){
                hi = mid; // isse kum dhundho jisse ho jaye
            }
            else{
                lo = mid+1; // mid kum pad gaya
            }

        }
        return lo;
    }
};