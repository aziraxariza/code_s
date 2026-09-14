class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); // wordList ke words in set dalo
        if(!st.count(endWord)) return 0; // end word tha hi nhi wordList mein

        queue<string> q; // to contain related words level by level from wordList
        q.push(beginWord);

        int levels = 1; // start level with beginWord

        while(!q.empty()){
            int sz = q.size(); // to process one level ke words at a time
            while(sz--){
                string word = q.front(); // get word
                q.pop();

                if(word == endWord) return levels; // found

                for(int i = 0; i < word.size(); i++){
                    char og = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch; // replace krke i ko dekho
                    
                        if(st.count(word)){
                            q.push(word); // ye wordList mein tha ab isko q mein dalo 
                            st.erase(word); // remove from st
                        }
                    }
                    word[i] = og; // ith posn par wapas og char dalo
                }
            }
            levels++;
        }
        return 0;
    }
};