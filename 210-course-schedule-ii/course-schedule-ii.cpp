class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // bi -> ai // hum store karenge bi mein bi ke baad kaunsa kar sakte hai course
        vector<vector<int>> adj(numCourses); // adj list
        vector<int> indegree(numCourses, 0); // indegree of each node

        for(auto it : prerequisites){
            int u = it[0]; // a
            int v = it[1]; // b

            adj[v].push_back(u); // b -> a typa format
            indegree[u]++;
        }

        queue<int> q; // for nodes

        vector<int> ans; // kahns algo

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front(); // get node
            q.pop();

            ans.push_back(node); // topo sort

            for(int nei : adj[node]){
                indegree[nei]--; // reduce indegree of nei
                if(indegree[nei] == 0){
                    q.push(nei); // q mein dalo
                }
            }
        }

        if(ans.size() != numCourses) return {}; // cycle hai
        return ans;
    }
};