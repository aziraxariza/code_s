class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // total nodes
        vector<int> color(n, -1); // stores color of each node

        queue<int> q; 
        for(int i = 0; i < n; i++){ //esp.. for disconnected
            if(color[i] != -1) continue; // alr visited/colored hai

            q.push(i); //node ko q mein dala
            color[i] = 0; // initial color 0 liya as A

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto nei : graph[node]){ // iske neighbour nodes
                    if(color[nei] == -1){
                        color[nei] = 1 - color[node]; // opposite of node's color
                        q.push(nei); // isko bfs ke liye q mein dala
                    }
                    else{ // agar nei colored hai aur same color ka nikla toh not bipartite
                        if(color[nei] == color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};