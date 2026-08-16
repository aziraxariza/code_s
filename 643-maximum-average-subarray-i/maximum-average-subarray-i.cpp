class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double iniAvg = 0; 

        for(int i = 0; i < k; i++){
            iniAvg += nums[i]; // pehle k chars ka sum initial avg ka numerator hoga
        }

        double maxAvg = iniAvg; // maxAvg numerator initially iniAvg hoga

        for(int j = k; j < nums.size(); j++){
            iniAvg += nums[j]; // ab kth idx wala jodo to update iniAvg's val
            iniAvg -= nums[j-k]; // peeche ka ek nikalo to maintain k length
            maxAvg = max(maxAvg, iniAvg);
        }
        return (double)maxAvg/k; // calculate avg and return
    }
};