class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); // u has {v,w}
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        // cost[node][stops] = minimum cost to reach node
        // with exactly stops flights
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq; // {cost, node, stops}

        pq.push({0, src, 0});
        cost[src][0] = 0;

        while(!pq.empty()){
            auto [c, node, stops] = pq.top();
            pq.pop();

            if(node == dst) return c;
            
            if(stops == k + 1) continue;// k stops means max k+1 flights
            for(auto [nei, wt] : adj[node]){

                if(c + wt < cost[nei][stops + 1]){
                    cost[nei][stops + 1] = c + wt;
                    pq.push({
                        cost[nei][stops + 1],
                        nei,
                        stops + 1
                    });
                }
            }
        }
        return -1;
    }
};