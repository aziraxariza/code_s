class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //multi source bfs kyuki level by level for each rotten simultaneously

        int m = grid.size(); // rows
        int n = grid[0].size(); // cols

        queue<pair<int, int>> q; // stores rotten oranges
        int fresh = 0; // counts fresh oranges

        //shuruat mein initial all rotten ko put in q 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j}); // shuruat wale rots
                if(grid[i][j] == 1) fresh++; // to keep track of fresh
            }
        }

        if(fresh == 0) return 0; // already rotten
        int minutes = 0; //keeps track of time | incr. after each bfs

        //directions
        int dr[] = {-1, 1, 0, 0}; // for row changing
        int dc[] = {0, 0, -1, 1}; // for row changing

        while(!q.empty()){
            int sz = q.size(); // taking ek baari mein kitne rotten sath
            bool rottenThisMinute = false; // did any orange rot this minute?

            while(sz--){
                auto[r, c] = q.front(); // get its row col
                q.pop(); // ho gaya ye

                for(int k = 0; k < 4; k++){ // for 4 dirxns
                    int nr = r + dr[k]; // row posn
                    int nc = c + dc[k]; // col posn

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){ // fresh hai aur grid ke limits mein hai i.e inside
                        grid[nr][nc] = 2; // make it rotten
                        fresh--; 
                        q.push({nr, nc});
                        rottenThisMinute = true; // iss min mein rotten hua
                    }
                }
            }
            if(rottenThisMinute) minutes++; // iss level par rotten mile
        }
        return (fresh == 0) ? minutes : -1; // fresh is now 0 toh minutes warna -1

    }
};