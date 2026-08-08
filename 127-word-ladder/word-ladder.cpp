class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); // vector wale sare words ek set mein daal diye

        if(!st.count(endWord)) return 0; // endWord nahi hai wordList mein

        queue<string> q;
        q.push(beginWord); // beginWord in q to start bfs

        int level = 1; // total changes

        while(!q.empty()){
            int sz = q.size(); //ek level walo ke liye i.e jinme ek letter ka farq

            while(sz--){
                string word = q.front(); // take the word
                q.pop();
                if(word == endWord) return level; // mil gaya

                for(int i = 0; i < word.size(); i++){// har ek char ke liye
                    char original = word[i]; // store kaunsa char par hai

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch; //switch liya ch se

                        if(st.count(word)){ // ye new word wordList mein hai
                            st.erase(word); //set se hatao to mark vis
                            q.push(word); // push in bfs q
                        }
                    }
                    word[i] = original; //switch back ith posn char to og
                }
            }
            level++; // nahi mila tha toh ek level up
        }
        return 0;
    }
};