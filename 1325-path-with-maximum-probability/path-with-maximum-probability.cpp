class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> adj(n); // adj list
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v,w}); 
            adj[v].push_back({u,w}); // since undirected
        }

        vector<double> probs(n, 0); // har ek tak ka prob 0 set initially
        priority_queue<pair<double, int>> pq; // max heap {v, prob}

        probs[start_node] = 1; // start node ki prob 1 set kyuki aage walo ki multiply karke nikle gi
        pq.push({1, start_node});

        while(!pq.empty()){
            auto[p, node] = pq.top();
            pq.pop();

            if(p < probs[node]) continue; // ignore if iski prob. kum hai

            for(auto [nei, wt] : adj[node]){
                if(p*wt > probs[nei]){ // bigger probability aayi toh usko set karo
                    probs[nei] = p*wt;
                    pq.push({probs[nei], nei}); // ab isse jude walo ki max prob set karo
                }
            }
        }
        return probs[end_node];
    }
};