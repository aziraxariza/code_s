class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int num : nums){ // val --> freq
            mp[num]++;
        }

        vector<pair<int,int>> vec; // store in vector as freq, val pair
        for(auto it : mp){
            vec.push_back({it.second, it.first}); // isko hum sort karenge to get most frequent ones
        }

        sort(vec.rbegin(), vec.rend()); // sort descending

        vector<int> ans;// pick k elements
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};