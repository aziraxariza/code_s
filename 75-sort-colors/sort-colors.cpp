class Solution {
public:
    void sortColors(vector<int>& nums) { // THREE PTRS
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]); // swap karo mid se
                low++;
                mid++; // low aur mid ++ when its 0
            }
            else if(nums[mid] == 1) {
                mid++; // 1 par sirf mid++
            }
            else { 
                swap(nums[mid], nums[high]);
                high--; // if 2 then swap and r--
            }
        }
    }
};
