class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1; // idx of l and r initially
        int leftMax = 0;
        int rightMax = 0; // height of biggest heights from l and r side

        int ans = 0; // final ans

        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] > leftMax){// chhoti height se karenge humesa
                    leftMax = height[l]; // l wala bada tha zayada so usko leftMax banaya 
                }
                else{
                    ans += leftMax-height[l]; // dono ke beech ka diff add to water
                }
                l++; // move aage
            }

            else{
                if(height[r] > rightMax){
                    rightMax = height[r];
                }
                else{
                    ans += rightMax-height[r];
                }
                r--;
            }
        }
        return ans; // O(n)
    }
};