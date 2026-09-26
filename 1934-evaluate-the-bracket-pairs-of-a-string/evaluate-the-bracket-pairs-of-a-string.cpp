class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp; // knowled key->val
        for(auto it : knowledge){
            mp[it[0]] = it[1]; // key->val
        }

        string ans = "";

        int i = 0;

        while(i < s.size()){

            if(s[i] == '('){
                queue<char> q;
                int j = i+1;
                while(s[j] != ')'){
                    q.push(s[j]);
                    j++;
                }
                string check = "";
                while(!q.empty()){
                    check += q.front();
                    q.pop();
                }
                ans += mp.find(check) != mp.end() ? mp[check] : "?";
                i = j+1;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};