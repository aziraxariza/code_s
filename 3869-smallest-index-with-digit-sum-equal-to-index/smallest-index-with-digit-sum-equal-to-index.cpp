class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];

            int sum_n = 0;
            while(n > 0){
                int rem = n%10;
                sum_n += rem;
                n /= 10;
            }
            if(sum_n == i) return i; 
        }
        return -1;
    }
};