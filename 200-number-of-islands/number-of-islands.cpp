class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return; // base

        grid[i][j] = '0'; // make water

        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid); // 4 dirxns
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // rows 
        int n = grid[0].size(); // cols

        int islands = 0; // total islands

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++; // island shuru
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};