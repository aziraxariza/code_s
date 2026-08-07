class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        if (mn == mx) return 0;

        int bucketSize = max(1, (mx - mn) / (n - 1));
        int bucketNum = (mx - mn) / bucketSize + 1;
        vector<int> bucketMin(bucketNum, INT_MAX), bucketMax(bucketNum, INT_MIN);

        for (int x : nums) {
            int idx = (x - mn) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
        }

        int result = 0, prev = -1;
        for (int i = 0; i < bucketNum; i++) {
            if (bucketMin[i] == INT_MAX) continue;
            if (prev != -1) result = max(result, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        return result;
    }
};