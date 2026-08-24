class Solution { //MST SE KIYA 
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n); // adj_list
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist}); // fully connected graph banaya sabhi nodes ko jodkr
            }
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq; // {wt, u} min heap

        vector<int> vis(n, 0); // all unvis
        pq.push({0, 0}); // first node ko push kiya 

        int ans = 0; // total min dist
        while(!pq.empty()){
            auto [wt, u] = pq.top();
            pq.pop();

            if(vis[u]) continue; // alr visit ho gaya toh ignore

            vis[u] = 1; // vis mark kiya
            ans += wt;

            for(auto [nei, dis] : adj[u]){
                if(!vis[nei]){
                    pq.push({dis, nei}); // dist of nei node aur node ko pq mein dala
                }
            }
        }  
        return ans;              
    }
};