class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; // start idx
        int r = height.size() - 1; // last idx

        int ans = 0;
        while(l < r){
            int length = r-l; // total distance bw the two
            int breadth = min(height[l], height[r]);

            ans = max(ans, length*breadth);

            if(height[l] > height[r]){
                r--; // jo bada hai usko rakhenge aur uske opposite ko badhayenge
            }
            else{
                l++;
            }
        }
        return ans;
    }
};