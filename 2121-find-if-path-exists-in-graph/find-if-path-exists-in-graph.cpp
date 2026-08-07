class Solution {
public:
    void dfs(int source, vector<vector<int>>& adj, int destination, vector<int> &vis, bool &flag){
        vis[source] = 1; // mark visited

        if(source == destination){
            flag = true; // mil gaya
            return;
        }

        for(auto it : adj[source]){ // src ke jude nodes
            if(!vis[it]){ //vis nahi hai
                dfs(it, adj, destination, vis, flag); // isse pata lagao
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // edges graph nahi hai so make adj list;
        int size = edges.size();
        vector<vector<int>> adj(n);
        for(auto &e : edges){ // make adj list
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // adj mein dono ke vals dali
        }

        bool flag = false; // abhi tak not found
        vector<int> vis(n, 0); //vis to keep track
        dfs(source, adj, destination, vis, flag);
        return flag;
    }
};