class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1; // idx of left and right
        int leftMax = 0; 
        int rightMax = 0;// max height from l and r side

        int ans = 0; // final ans
        while(l < r){

            // JO CHHOTI HEIGHT UDHAR SE PROCESS KARENGE ****
            if(height[l] <= height[r]){ 
                if(height[l] > leftMax){
                    leftMax = height[l]; // update bigger height from left side
                }
                else{
                    ans += leftMax - height[l]; // dono ka diff is water bw them
                }
                l++; // next l 
            }

            else{
                if(height[r] > rightMax){
                    rightMax = height[r]; 
                }
                else{
                    ans += rightMax - height[r]; 
                }
                r--; // next r
            }
        }
        return ans;
    }
};