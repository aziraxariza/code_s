class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans; 

        unordered_map<int, int> mp; // val -> freq
        for(int x : nums){
            mp[x]++; 
        }

        priority_queue<pair<int, int>> pq; // {freq, val} max heap
        for(auto& it : mp){
            pq.push({it.second, it.first});
        }

        while(k--){ // to get top k
            auto check = pq.top(); // {freq, val}
            pq.pop(); // remove from pq
            ans.push_back(check.second); // val ko ans mein dala
        }
        return ans;
    }
};