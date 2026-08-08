class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); // rows
        int n = mat[0].size(); // cols

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    q.push({i,j}); // sabhi 0 source hain
                else
                    mat[i][j] = -1; // 1 ko unvisited mark karo
            }
        }

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1}; // 4 directions

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k]; // agal bagal 

                if(nr >= 0 && nr < m && nc >= 0 && nc < n 
                   && mat[nr][nc] == -1){ // i.e unvisited hai

                    mat[nr][nc] = mat[r][c] + 1; // distance = jisse bfs call usme +1
                    q.push({nr,nc}); // next BFS level
                }
            }
        }

        return mat;
    }
};