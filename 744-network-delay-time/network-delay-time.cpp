class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        // u, v, w --> times[i]

        vector<vector<pair<int,int>>> adj(n+1); // stores u ke {v, w}
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w}); // push u se jane wale v ko aur uske w ko
        }

        vector<int> dist(n+1, INT_MAX); // sabhi ka curr dist inf hai
        dist[k] = 0; // src ki dist

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {w, node}
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, node] = pq.top(); // curr node liya
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [nei, wt] : adj[node]){ // iske neighbors traverse karke dekho
                if(d + wt < dist[nei]){
                    dist[nei] = d+wt; // naya dist bana do
                    pq.push({dist[nei], nei});
                }
            }
        }
        int ans = 0; // total kinna time

        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX)
                return -1; // koi node unreachable hai still

            ans = max(ans, dist[i]); // max ko lete jayenge 
        }

        return ans;
    }
};