class Solution { // just like lc 1011 of bag and their weights and max capacity
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end()); // minimum possible answer
        int hi = accumulate(nums.begin(), nums.end(), 0); // maximum possible answer

        while(lo < hi){
            int mid = lo + (hi - lo) / 2; // maximum allowed subarray sum

            int subarrays = 1; // start with first subarray
            int sum = 0; // current subarray ka sum

            for(int x : nums){
                if(sum + x > mid){ // current element fit nahi ho raha i.e cap ko exceed kar raha
                    subarrays++; // new subarray banao
                    sum = 0; // naya subarray ka sum 0 initialise
                }

                sum += x; // current element ko sum mein add 
            }

            if(subarrays <= k){ // toh okayyy!
                hi = mid; // possible hai, aur smaller answer try karo
            }
            else{
                lo = mid + 1; // capacity badhao since zyada ban gaye aubarrays
            }
        }
        return lo; // minimum sum of subarray that is possible
    }
};