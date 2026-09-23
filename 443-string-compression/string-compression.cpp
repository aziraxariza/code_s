class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int write = 0;

        while(i < chars.size()) {

            char ch = chars[i];
            int j = i;

            while(j < chars.size() && chars[j] == ch)
                j++;  // jab tak same hai, aage badho

            int freq = j - i;  // current character ki frequency

            chars[write++] = ch;

            if(freq > 1) {
                string temp = to_string(freq);
                for(char c : temp)
                    chars[write++] = c;
            }
            i = j;  // next different character
        }
        return write;
    }
};

/* without updating chars vector
class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0;

        while(i < chars.size()) {
            char ch = chars[i];
            int j = i;

            while(j < chars.size() && chars[j] == ch)
                j++;  // jab tak same tab tak aage badho

            int freq = j - i; // to get freq of curr ch

            s += chars[i];
            s += to_string(freq);

            i = j; // now to next diff char
        }

        return s.size();
    }
};
*/