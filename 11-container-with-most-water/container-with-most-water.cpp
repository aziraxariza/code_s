class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1; // l and r ptrs

        int ans = 0;
        while(l < r){
            int width = min(height[l], height[r]); // chhoti height lenge as common
            int length = r-l;
            ans = max(ans, width*length); // update ans

            if(height[l] > height[r]){
                r--; // keep bigger height
            }
            else{
                l++;
            }
        }
        return ans;
    }
};