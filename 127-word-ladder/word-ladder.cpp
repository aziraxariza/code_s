class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); // wordList ke saare words store kar liye
        if(!st.count(endWord)) return 0; // hai hi nahi words ki list mein end word

        queue<string> q;
        q.push(beginWord); // first word ko q mein dala
        int level = 1;

        int cnt = 0;
        while(!q.empty()){
            int sz = q.size(); 
            while(sz--){
                string word = q.front(); // word liya
                q.pop();
                if(word == endWord) return level; // mil gaya 

                for(int i = 0; i < word.size(); i++){
                    char og = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch;
                        if(st.count(word)){ // ye naya shabd wordList mein tha aur word ka koi ek char change karke aaya
                           q.push(word); 
                           st.erase(word); // ye word ho gaya
                        }
                       
                    }
                    word[i] = og; // switch to og word
                }
            }
            level++; // iss level ke hogaye i.e jitne words ek char ko change karke bane current word se 
        }
        return 0;
    }
};