class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp; // isme 2 fruits rahenge with fruits --> freq
        int l = 0; // peeche wala fruit sabse
        int ans = 0; // max length

        for(int r = 0; r < fruits.size(); r++){
            mp[fruits[r]]++;

            while(mp.size() > 2){ // 2 type se zyada fruits ho gye

                mp[fruits[l]]--; // sabse starting wale type ko reduce karo
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]); // isko mp se hatao ab jab ye 0 hai
                }
                l++; // after each removal move l forwrd
            }
            ans = max(ans, r-l+1); // dist bw initial and curr posn
        }
        return ans;
    }
};