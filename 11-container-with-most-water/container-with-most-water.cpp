class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1; // idx of kone ke heights

        int ans = 0; // final ans
        while(l < r){
            int breadth = min(height[l], height[r]); // chhoti wali lenge
            int length = r-l; 

            ans = max(ans, length*breadth); // update ans

            if(height[l] < height[r]){
                l++; // jo height badi hai woh rahegi
            }
            else{
                r--;
            }
        }
        return ans; // O(n)
    }
};