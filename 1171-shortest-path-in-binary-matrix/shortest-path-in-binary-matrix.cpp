class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // no. of rows and cols

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // not possible

        int dr[] = {1,1,1,-1,-1,-1,0,0}; // 8 dirxns ke liye
        int dc[] = {-1,0,1,-1,0,1,-1,1}; 

        int dist = 1; // initially dist 1 lekar chalo

        queue<pair<int, int>> q; // {row, col}
        q.push({0, 0}); // first cell dalo 

        while(!q.empty()){
            int sz = q.size(); // ek level ke cells same dist par process honge
            while(sz--){
                auto [r, c] = q.front();
                q.pop();

                if(r == n-1 && c == n-1) return dist; // end tak aa gaye

                for(int k = 0; k < 8; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k]; // 8 adj cell ke liye

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                        grid[nr][nc] = 1; // mark vis
                        q.push({nr, nc}); // q mein dalo isko
                    }
                }
            }
            dist++; // ek level ke baad dist badhaya
        }
        return -1;
    }
};