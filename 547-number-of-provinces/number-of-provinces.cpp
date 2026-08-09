class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1; // mark visited

        for(int j = 0; j < isConnected.size(); j++) { // usse jude hue khojne ke liye adj matrix mein
            if(isConnected[node][j] == 1 && !vis[j])
                dfs(j, isConnected, vis); // usse jude hai toh dfs mein ghumo aur visited mark karo
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0); // made visited to track each node

        int province = 0;

        for(int i = 0; i < n; i++) { // har ek node
            if(!vis[i]) { // nahi kiya visit toh
                province++; // naya province shuru
                dfs(i, isConnected, vis); //isse connected
            }
        }
        return province;
    }
};