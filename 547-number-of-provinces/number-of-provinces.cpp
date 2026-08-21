class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[i] = 1; // mark visited iss node ko

        for(int j = 0; j < isConnected.size(); j++){ 
            if(isConnected[i][j] == 1 && !vis[j]){ // i se jude nodes 
                dfs(j, isConnected, vis); // inka dfs kar diya vis mark kr diya as well
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // no. of rows for here tho dono row cols same hai
        vector<int> vis(n, 0); // to mark vis nodes

        int provinces = 0; // for provinces cnt
        for(int i = 0; i < n; i++){
            if(!vis[i]){ // agar unvisited hai node
                provinces++; // ye ek province hua shuru // saare disconnected components ke beg se provinces mark ho jayengi
                dfs(i, isConnected, vis); // connected nodes dfs se vis mark ho jayengi
            }
        }

        return provinces;
    }
};