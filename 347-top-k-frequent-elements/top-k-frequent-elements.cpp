class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // ele --> freq;
        for(int x : nums){
            mp[x]++; // sabko map mein dala
        }

        priority_queue<pair<int, int>> pq; // max heap storing (freq, ele)
        for(auto it : mp){
            pq.push({it.second, it.first}); // apne aap freq ke acc store hongi
        }

        vector<int> ans; //final ans storing top k frequent eles
        for(int i = 0; i < k; i++){
            int val = pq.top().second; // hume ele chahiye pair se
            pq.pop(); // isko heap se nikala
            ans.push_back(val); // ans mein dala
        }
        return ans;
    }
};