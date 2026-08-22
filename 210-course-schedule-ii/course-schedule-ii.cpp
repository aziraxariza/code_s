class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); // har ek cousre ki indegree

        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1]; // pehle 1 karna padega
            int v = prerequisites[i][0]; // 1 --> 0

            adj[u].push_back(v);
            indegree[v]++; // v ki indegree update ki
        }
        vector<int> ans; // order of courses 

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i); // sabse pehle 0 indegree wale daal diye q mein 
            }
        }

        while(!q.empty()){
            int course = q.front(); // cousre liya
            q.pop();
            ans.push_back(course); // ans mein dala

            for(int nei : adj[course]){
                indegree[nei]--; // har nei ki indegree kum karo by 1
                if(indegree[nei] == 0){
                    q.push(nei); // agar indegree nei ki 00 hui toh q mein dalo
                }
            }
        }
        if(ans.size() != numCourses) return {}; // cycle ban gayi, not possible
        return ans;
    }
};