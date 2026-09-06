class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;

        for(int fast = 1; fast < nums.size(); fast++){
            if(nums[fast] != nums[slow]){
                slow++; // agar same nahi toh slow ko ek badha kar uss posn par nums[j] val daal do 
                nums[slow] = nums[fast];
                // agar dono same hote tohslow wahi ruka rehta aur jaise hi koi different aata woh slow + 1th posn par update karta
            }
        }
        return slow + 1; // slow jis idx par hai usse ek zyada unique numbers hai
    }
};

/*  visualise
nums = [1,2,3,2,3]
       ↑─────↑
       first k=3 */ 