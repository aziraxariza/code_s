class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        map<char, int> mp; // map karo char --> freq
        for(char x : word){
            mp[x]++; // har char --> freq store
        }
        vector<int> v;
        for(auto it : mp){
            v.push_back(it.second); // har freq ko vector mein dala
        }
        sort(v.rbegin(), v.rend()); // freq ke acc sorted desc order mein

        for(int i = 0; i < v.size(); i++){
            ans += v[i] * ((i/8) + 1); // freq into kitni baar button dabana hai
        }
        return ans;
    }
};