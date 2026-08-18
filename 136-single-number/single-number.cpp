class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // perfect xor soln since jo  more than one times hai woh ^ se 0 ban jayenge jo bachega woh only once tha

        int ans = 0;
        for(int x : nums){
            ans ^= x; // XOR liya sabka one after the other
        }
        return ans;
    }
};

/*unordered_map<int, int> mp; // val --> freq

        for(int x : nums){
           mp[x]++;
        } 

        for(auto it : mp){
            if(it.second == 1) return it.first;
        }

        return 0;*/