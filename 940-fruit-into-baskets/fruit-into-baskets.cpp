class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp; // val -> freq // hum at max mp mein 2 hi rakhenge fruits
        int ans = 0; // continuous trees of 2 fruits

        int l = 0;
        for(int r = 0; r < fruits.size(); r++){
            mp[fruits[r]]++; // iski freq add mp mein

            while(mp.size() > 2){ // agar 2 se zyada types ke fal ho gaye
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){ // ye khatam ho gaya toh
                    mp.erase(fruits[l]);
                }
                l++; // l aage badhaya
            }

            ans = max(ans, r-l+1); // cur continuous window se zyada mile kya fal?
        }
        return ans;
    }
};