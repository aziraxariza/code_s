class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // represent A --> 0 and B --> 1
        int n = graph.size();
        vector<int> color(n, -1); // mark kiya all as uncolored

        for(int i = 0; i < n; i++){
            if(color[i] != -1) continue; // dusre node par se continue if ye colored hai

            queue<int> q; // store nodes
            q.push(i); // iss uncolored node ko q mein dala
            color[i] = 0; // color kiya node ko

            while(!q.empty()){
                int node = q.front(); // liya isko as parent
                q.pop();

                for(int nei : graph[node]){ // iske neeche jude level wale dekho
                    if(color[nei] == -1){ // uncolred hai toh
                        color[nei] = 1 - color[node]; // opposite color kiya
                        q.push(nei); // isko push to check baaki level wise jude nodes
                    }
                    else if(color[nei] == color[node]){ // colored and same as node ka color
                        return false; // takes care when not possible
                    }
                }
            }
        }
        return true; 
    }
};