class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); // row col liya

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return; // base cases

        grid[i][j] = '0'; // isko pani bana do

        dfs(i + 1, j, grid); // all 4 dircns mein same karo for one continuos piece of land
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) { // traverse grid get 1s jo hai
                if (grid[i][j] == '1') {
                    islands++; // island shuru
                    dfs(i, j, grid); // ab hum agal bagal ko traverse karenge aur pani bana denge
                }
            }
        }

        return islands;
    }
};