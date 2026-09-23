class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int l1 = INT_MIN, l2 = INT_MIN, l3 = INT_MIN;
        int s1 = INT_MAX, s2 = INT_MAX;

        for(int x : nums) {

            // 3 largest 
            if(x >= l1) {
                l3 = l2;
                l2 = l1;
                l1 = x;
            }
            else if(x >= l2) {
                l3 = l2;
                l2 = x;
            }
            else if(x > l3) {
                l3 = x;
            }

            // 2 smallest what if 2 -ves
            if(x <= s1) {
                s2 = s1;
                s1 = x;
            }
            else if(x < s2) {
                s2 = x;
            }
        }

        return max(l1 * l2 * l3, l1 * s1 * s2);
    }
};

/*
int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return max(nums[n-1] * nums[n-2] * nums[n-3],
                   nums[0] * nums[1] * nums[n-1]);
    }
*/