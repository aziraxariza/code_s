class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // pehle hi impossible

        queue<pair<int, int>> q; //bfs q
        int dist = 1; // initial dist

        q.push({0,0}); // starting posn
        grid[0][0] = 1; // visited mark kiya

        int dr[] = {1,-1,0,0,-1,-1,1,1}; // for 8 dirxns
        int dc[] = {0,0,1,-1,-1,1,-1,1};


        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [r, c] = q.front(); // get posn
                q.pop();

                if(r == n-1 && c == n-1) return dist; // end takk pohoch gaye **

                for(int k = 0; k < 8; k++){
                    int nr = r + dr[k]; // get posn of agal bagal 
                    int nc = c + dc[k]; 

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                        grid[nr][nc] = 1; // mark visited
                        q.push({nr,nc});
                    }
                }
            }
            dist++; // entire level ke baad dist + hoga
        }
        return -1;
    }
};