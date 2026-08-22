class Solution { //CYCLE DETECTION se karna hai 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // kahns algo se 
        vector<int> indegree(numCourses, 0);

        for(auto p : prerequisites) { // adj list
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) { // course jinke no prerequisites
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return count == numCourses;
    }
};