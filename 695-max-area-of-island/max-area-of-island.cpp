class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int &area){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return; // no land, paani hai

        area++; // add land
        grid[i][j] = 0; // make water to mark visited

        dfs(i+1, j, grid, area); // all 4 dirxns
        dfs(i-1, j, grid, area);
        dfs(i, j+1, grid, area);
        dfs(i, j-1, grid, area);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        vector<int> areas; // store karega har ek island ka area
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    islands++; // island shuru
                    int area = 0; //area shuru mark - har ek dfs of land ke baad +1 hoga
                    dfs(i, j, grid, area);
                    areas.push_back(area);
                }
            }
        }
        sort(areas.begin(), areas.end()); // sort kar diya area wise
        int k = areas.size();
        return islands ? areas[k-1] : 0; // koi island hai toh biggest area else 0
    }
};