class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end()); // store karega deadends

        if(dead.count("0000")) return -1; // start hi deadend hai

        queue<string> q; // store karega possible combos
        q.push("0000");
        unordered_set<string> vis; // to keep track of visited combos;
        vis.insert("0000");

        int level = 0; // kitne levels as in combos of +-1

        while(!q.empty()){
            int sz = q.size(); // kitne level of combos done
            while(sz--){
                string curr = q.front();
                q.pop();
                if(curr == target) return level; // mila itne levels ke baad

                for(int i = 0; i < 4; i++){ // to get possible combos +1 -1 karge each char in code ke i.e in total 8 combos
                    string next = curr;

                    next[i] = (curr[i] - '0' + 1)%10 + '0'; // +1 kiya ith char ko
                    if(!dead.count(next) && !vis.count(next)){ /// na hi dead hai na hi visited
                        vis.insert(next); // mark visited
                        q.push(next); //possible path to get target
                    }

                    next[i] = (curr[i] - '0' + 9)%10 + '0'; // -1 kiya ith char ko
                    if(!dead.count(next) && !vis.count(next)){
                        vis.insert(next);
                        q.push(next); 
                    }
                }
            }
            level++; // ek level of combos done
        }
        return -1;
    }
};