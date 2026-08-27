// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2; // mid version dekha
            if(isBadVersion(mid)){
                hi = mid-1; // isse chhota version dhundho
            }
            else{
                lo = mid+1; // isse bada version kharab hoga
            }
        }
        return lo;
    }
};