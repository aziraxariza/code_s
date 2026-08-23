class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); // no. of rows
        int n = mat[0].size(); // cols

        queue<pair<int, int>> q; // isme sare jayenge but pehle saare 0s jayenge
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j}); // 0 ke i j ko push karenge
                }
                else{
                    mat[i][j] = -1; // to mark it unvisited
                }
            }
        }

        int dr[] = {1, -1, 0, 0}; 
        int dc[] = {0, 0, 1, -1}; // 4 dirxns ke liye

        while(!q.empty()){
            auto [r, c] = q.front(); // isko uthaya
            q.pop();

            for(int k = 0; k < 4; k++){ 
                int nr = r + dr[k];
                int nc = c + dc[k]; 

                // agalbagal ke -1 ke dist update r c ki madad se
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1){
                    // sirf iske adjacent -1 i.e unvis 1 walo ki update karenge dist

                    mat[nr][nc] = mat[r][c] + 1; // jiska adj hai uski 0 se dist. +1
                    q.push({nr, nc}); // ab isse jude -1 ke 0 se dist iskadist+1 honge 
                }
            }
        }
        return mat; 
    }
};