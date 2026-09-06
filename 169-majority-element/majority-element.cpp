class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore voting algo   // TC: O(n) SC: O(1)
        int candidate = 0;
        int count = 0;
        for(int x : nums){
            if(count == 0){
                candidate = x;
            }
            if(x == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate; // ele w most appearence
    }
};

/* TC: O(n) ; SC: O(n)
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mp; // val --> freq 
        for(int x : nums){
            mp[x]++;
            if(mp[x] > n/2) ans = x;
        }
        return ans;
*/
