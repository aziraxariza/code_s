class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1; // required flowers > garden mein flowers

        int lo = *min_element(bloomDay.begin(), bloomDay.end()); // sabse kum kitne din mein uga
        int hi = *max_element(bloomDay.begin(), bloomDay.end()); // max kitne din mein uga

        while(lo < hi){
            int mid = lo + (hi-lo)/2; // mid as in itne din tak le kar chalo wait time to get all bouquets

            int flowers = 0; // is  mid ke acc kitne flowers hue
            int bouquets = 0; // kitne bouquets complete

            for(int x : bloomDay){
                if(x <= mid){ // mid ya usse kum din mein ug gaya
                    flowers++; // ek flower lelo

                    if(flowers == k){
                        bouquets++; // ek bouquet complete
                        flowers = 0; // new bouquet ke liye val 0 set krdo wapas
                    }
                }
                else{ // mid se zyada  din mein uga
                    flowers = 0; // set flowers to 0 kyuki hume adj flowers chahiye ek bouquet mein
                }
            }

            if(bouquets >= m){
                hi = mid; // mid se kum days check karo ki suffice kr rhe hai 
            }
            else{
                lo = mid+1; // zyada din chahiye since bouquets nahi bane saare
            }
        }
        return lo; // kum se kum din jisme sare bouquet bn jaye
    }
};