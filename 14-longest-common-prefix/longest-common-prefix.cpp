class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return ""; // koi str nahi thi

        string prefix = strs[0]; // initially first wale ko prefix rakha poora
        
        for(string s : strs){
            while(s.find(prefix) != 0){ // jab tak s ke 0th idx se prefix nhi milta
                prefix = prefix.substr(0, prefix.size()-1); // jo prefix tha uske peeche se char hatana start
            }
        }
        return prefix; // common prefix of all
    }
};
