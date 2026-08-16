class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);

            if (height[l] < height[r]) // jiski height kum usse aage badhenge
                l++;
            else
                r--;
        }

        return ans;
    }
};