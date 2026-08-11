class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n+1); // make its adj list
        for(int i = 0; i < dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v); // uss node u ke posn in adj par add v
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1); // to keep track of diff ppl

        for(int i = 1; i < n+1; i++){
            if(color[i] != -1) continue; // yani alr visited hai isliye chhodo

            color[i] = 0; // initialise color
            queue<int> q; // is node se shuru kiya bfs
            q.push(i); // isko q mein dala

            while(!q.empty()){
                int node = q.front(); // node liya
                q.pop();

                for(int nei : adj[node]){ // isse jude hue dekho
                    if(color[nei] == -1){ // agar uncolored hai
                        color[nei] = 1 - color[node]; // opp. of node color kiya
                        q.push(nei); // next level ko q mein dala
                    }
                    else if(color[nei] == color[node]){
                        return false; // colored hai aur same hai jude hue walo se
                    }
                }
            }
        }
        return true; 

        /* basically opp. ppl ko ek dusre joda to keep track that they can't be painted the same*/
    }
};