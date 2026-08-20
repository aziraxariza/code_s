class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0; // starting ptr
        int r = height.size()-1; // end ptr
        int leftMax = 0; // max height from left side
        int rightMax = 0; 

        int ans = 0; // final answer
        while(l < r){
            if(height[l] < height[r]){// humesha chhoti height se process karenge
                if(height[l] > leftMax){
                    leftMax = height[l]; // biggest height from l as of now
                }
                else{ // agar leftMax  height se chhota hai toh uska height difference hoga water added
                    ans += leftMax - height[l];
                }
                l++; // left se aage badhao for next
            }
            else{ // r par chhoti height udhar se process karo ab
                if(height[r] > rightMax){
                    rightMax = height[r]; // biggest height from r as of now
                }
                else{
                    ans += rightMax - height[r];
                }
                r--; // peeche badhao right se
            }
        }
        return ans; 
    }
};