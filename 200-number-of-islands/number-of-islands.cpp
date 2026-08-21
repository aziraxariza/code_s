class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        
        grid[i][j] = '0'; // isko paani banaya to mark it as visited
        
        dfs(i+1, j, grid); // continuos piece of island ka land 4 dirns mein check
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid); // make agal bagal ka land as 0 if 1
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // no. of rows
        int n = grid[0].size(); // cols
        int islands = 0; 

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