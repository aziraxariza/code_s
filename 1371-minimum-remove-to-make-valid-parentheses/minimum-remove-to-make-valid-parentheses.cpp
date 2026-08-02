class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t;

        int open = 0;

        for(char c : s){
            if(c == '('){
                open++;
                t += c;
            }
            else if(c == ')'){
                if(open == 0)
                    continue;

                open--;
                t += c;
            }
            else
                t += c;
        }

        string ans;
        int close = 0;

        for(int i = t.size()-1; i >= 0; i--){
            char c = t[i];

            if(c == ')'){
                close++;
                ans += c;
            }
            else if(c == '('){
                if(close == 0)
                    continue;

                close--;
                ans += c;
            }
            else
                ans += c;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};