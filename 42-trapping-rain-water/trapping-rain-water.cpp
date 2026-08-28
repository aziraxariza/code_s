class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0;
        int rightMax = 0; // max height from left and right

        int ans = 0;
        while(left < right){

            if(height[left] <= height[right]){ // jis side height kum udhar se calc shuru
                if(height[left] > leftMax){ // isko leftMax banao
                    leftMax = height[left];
                }
                else{
                    ans += leftMax - height[left]; // add diff to get unit of water
                }
                left++; // left se aage badhao
            }

            else{
                if(height[right] > rightMax){ // isko leftMax banao
                    rightMax = height[right];
                }
                else{
                    ans += rightMax - height[right]; // add diff to get unit of water
                }
                right--; // right se peeche
            }

        }
        return ans;
    }
};