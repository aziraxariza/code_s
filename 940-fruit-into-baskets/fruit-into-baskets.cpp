class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp; // to keep track of 2 types of fruits.. 
        
        int l = 0;
        int ans = 0;

        for(int r = 0; r < fruits.size(); r++){
            mp[fruits[r]]++; // add kiya ye fruit

            while(mp.size() > 2){ // agar size bada hua 2 i.e more than 2 types of fruits a,b + c 
                mp[fruits[l]]--; // jab tak size 2 se zyada tab tak hatao jo shuruat mein hai i.e a ke saare hatao

                if(mp[fruits[l]] == 0)
                    mp.erase(fruits[l]); // iss type ke ab zero hai 
                l++; // keep incr l after each removal
            }
            ans = max(ans, r - l + 1); // max length track karne ke liye
        }
        return ans;
    }
};