       /* BRUTE FORCE
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp; // string --> freq
        for(string s : words){
            mp[s]++; 
        }

        priority_queue<pair<int, string>> pq; // stores max to min string by freq
        for(auto it : mp){
            pq.push({it.second, it.first}); // (freq, string) pairwise

        }

        vector<string> ans;
        for(int i = 0; i < k; i++){ // k times get top 
            string w = pq.top().second;
            pq.pop();
            ans.push_back(w);
        }
        return ans; */

class Solution {
   public:

    struct cmp{

        bool operator()(pair<int,string>& a, pair<int,string>& b){

            if(a.first == b.first) // agar dono words ki frequency same hai
                return a.second > b.second; // lexicographically bada word lower priority paaye, taaki chhota word top par aaye BASICALLY IDHAR PRIORITY ASSIGN KAR RAHE HAI NA KI COMPARISON
            // agar true aaya toh uska higher priority if false then opposite
            return a.first < b.first; // jiski frequency kam hai uski priority kam hogi, max frequency top par aayegi
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mp; // word -> frequency

        for(string s : words)
            mp[s]++;// har word ki frequency count 

        priority_queue< // ***
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > pq;  // custom comparator wala max heap

        for(auto &it : mp){
            pq.push({it.second,it.first}); // (frequency, word) store 
        }
        vector<string> ans;

        while(k--){  // top k frequent words nikalne hain
            ans.push_back(pq.top().second);// pair ka second is actual word
            pq.pop(); // next pane ke liye now pop
        }
        return ans;
    }
};
