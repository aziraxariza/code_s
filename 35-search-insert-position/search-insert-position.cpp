class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target) // mil gaya
                return mid;
            else if (nums[mid] < target) // low badhaya posn
                l = mid + 1;
            else
                h = mid - 1;
        }

        return l;// ab jab nahi mila toh jo lower posn rahi woh hogi target ki intended posn
    }
};
