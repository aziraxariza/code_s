class Solution { // MULTI SOURCE BFS
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // no. of rows
        int n = grid[0].size();

        queue<pair<int, int>> q; // stores {i,j} of rotten
        int fresh = 0; // fresh oranges

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j}); // sare rotten ko sath mein daal diya q mein
                }
                if(grid[i][j] == 1){
                    fresh++; // fresh cnt kar lo
                }
            }
        }

        int dr[] = {+1, -1, 0, 0}; 
        int dc[] = {0, 0, +1, -1}; // 4 dixns adj to cell

        int minutes = 0; // final ans hoga

        while(!q.empty()){
            int sz = q.size();
            bool rottenThisMin = false; // kya iske bagal mein rotten tha aage pata lagane ke liye
            while(sz--){
                auto [r, c] = q.front(); // liya i j of this rotten orange
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k]; // r c ke adjacent 4 dirxns ke i j
                    int nc = c + dc[k]; 

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        //bounds mein hai aur 1 hai toh rot karo
                        grid[nr][nc] = 2; // rotten banaya
                        fresh--; // reduce fresh cnt

                        q.push({nr, nc});
                        rottenThisMin = true; // iss minute agal bagal rotten mil gaya
                    }
                }
            } 
            if(rottenThisMin) minutes++;  // agar iss min koi rotten mila toh incr min
        }
        return (fresh == 0) ? minutes : -1; // agar sare rotten toh mins return warna -1
    }
};