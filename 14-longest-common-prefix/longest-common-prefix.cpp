class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {

            while (strs[i].find(prefix) != 0) { // jab strs[i] mein prefix nahi aata
                prefix = prefix.substr(0, prefix.size() - 1); // prefix ko short kiya substr le kar peeche se ek ek hata kar toh jo common tha woh reh gaya prefix mein
                if (prefix.empty()) return ""; // agar prefix empty hua then not possible
            }
        }
        return prefix;
    }
};
