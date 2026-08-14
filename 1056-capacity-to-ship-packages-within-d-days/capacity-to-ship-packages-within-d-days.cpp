class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()); // kyuki kum se kum cap jab max ele hogi tabh toh max ele ko chadha payenge ship par
        int hi = accumulate(weights.begin(), weights.end(), 0); // kyuki agar sirf ek din hua toh sabko sath mein dalna hoga u

        while(lo < hi){
            int mid = lo + (hi-lo)/2; // beech capacity le rahe as max possible capacity for now

            int total = 0; // total weights accumulated of bags
            int usedDays = 1; // pehle din se shuru

            for(int x : weights){
                if(total + x > mid){ // current package fit nahi ho raha cap mein
                    usedDays++; // zyada aa gaya weight toh ab agle din       // agar kum aaya toh total + x same day tak rahega
                    total = 0; // naya din empty start karo
                }

                total += x; // weight add kardo   // if cap se kum hai toh total usedDay x ke under add hote jayenge    // else naya day shuru ho gaya toh ab total uske acc add hote jayega
            }

            if(usedDays <= days) hi = mid; // total usedDays days se kumm aaye toh usse kum se check karo
            else lo = mid + 1; // zyada din lag gaye, capacity badhao i.e mid
        }
        return lo;
    }
};