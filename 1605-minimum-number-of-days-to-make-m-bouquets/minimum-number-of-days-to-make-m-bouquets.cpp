class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m * k > n) return -1; // not enough flowers

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            int flowers = 0;
            int bouquets = 0;

            for(int x : bloomDay){
                if(x <= mid){
                    flowers++;

                    if(flowers == k){
                        bouquets++;
                        flowers = 0;
                    }
                }
                else{
                    flowers = 0;
                }
            }

            if(bouquets >= m){
                hi = mid - 1; // mid works, try fewer days
            }
            else{
                lo = mid + 1; // need more days
            }
        }
        return lo;
    }
};