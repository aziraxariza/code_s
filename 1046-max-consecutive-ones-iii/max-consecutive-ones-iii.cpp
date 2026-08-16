class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        int zeros = 0;

        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0){
                zeros++; // add zero count
            }

            while(zeros > k){ // ab agar zeros k se zyada ho gaye toh k zeros convert karo 1 mein
                if(nums[l] == 0){
                    zeros--; // maan lo inn zeros ko 1 bana diya
                }
                l++; // aage zero par lane ke liye jo 
            }
            ans = max(ans, r-l+1); // jab tak zero k exceed nahi karega tab tak length mein woh add honge
        }
        return ans;
    }
};
