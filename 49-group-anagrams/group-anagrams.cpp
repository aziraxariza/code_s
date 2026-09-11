class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans; // final ans
        unordered_map<string, vector<string>> mp; // mp[sorted] -> {s1, s2..}

        for(string s : strs){ // O(n * klogk)
            string key = s;
            sort(key.begin(), key.end()); //  key ko sort kr diya 
            mp[key].push_back(s); // mp[aet] -> {eat, tea, ate} hote jayega
        }

        for(auto it : mp){
            ans.push_back(it.second); // har group ko daalo ans mein
        }
        return ans;
        // TC: O(n * k log k)
        // SC: O(n * k)
    }
};