class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> check;

        for(string s : strs){
            string s2 = s;
            sort(s2.begin(), s2.end());
            check.push_back({s2, s}); // s aur uske sorted ko check mein dala
        }
        sort(check.begin(), check.end()); // sort check for anagrams to be beside each othr

        int l = 0;
        vector<string> same;
        vector<vector<string>> ans;

        same.push_back(check[l][1]); 

        for(int r = 1; r < check.size(); r++){
            if(check[r][0]==check[l][0]){
                same.push_back(check[r][1]); // same hai l se uske sath dalo
            }
            else{
                ans.push_back(same); // alag hua jaise waise pehle walo ko dala as 1 level
                same.clear(); // khali kiya same ko
                l = r; // new checked posn
                same.push_back(check[r][1]);
            }
        }
        ans.push_back(same); // last group ko push to ans kyuki woh sirf same mein reh jayenge upar wale if else se

        return ans;
    }
};