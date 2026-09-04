class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // mp[key] = {x, y..}

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sort key

            mp[key].push_back(s); // og word mp[key] mein
        }

        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second); // ans mein vals dalo 
        }

        return ans;
    }
};