class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(); // no. of rows
        int n = heights[0].size(); // cols

        vector<vector<int>> efforts(m, vector<int> (n, INT_MAX)); // stores efforts for each node
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq; // min heap {diff, i, j}

        pq.push({0, 0, 0}); 
        efforts[0][0] = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1}; // 4 adj dirxns ke liyw

        while(!pq.empty()){
            auto[e, r, c] = pq.top();
            pq.pop();

            if(e > efforts[r][c]) continue; // zyada effort ko ignore
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(e, diff); // ** abhi tak iss raste ka sabse max mana jayega 
                    if(newEffort < efforts[nr][nc]){
                        efforts[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        return efforts[m-1][n-1];
    }
};