class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int currArea){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0; // bounds

        currArea++; // iss piece ka area badhaya
        grid[i][j] = 0; // to mark visited iss land ko 0 bana diya

        currArea += dfs(i+1, j, grid, 0); // 4 dirxns se area add karwao
        currArea += dfs(i-1, j, grid, 0); // 0 isliye currArea taaki unique lands add ho
        currArea += dfs(i, j+1, grid, 0);
        currArea += dfs(i, j-1, grid, 0); // sabhi ko add karna hai currArea mein unse kitne jude hai sab add hote jayenge initial currArea se 

        return currArea; // iss poore piece ka area jo aaya return karo
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(); // no. of rows
        int n = grid[0].size(); // cols

        int ansArea = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){ // island shuru
                    int currArea = dfs(i, j, grid, 0); // dfs se agal bagal mila kar area
                    ansArea = max(ansArea, currArea);
                }
            }
        }
        return ansArea; // kis land ka sabse zyada area
    }
};

/*  A TAD BIT SIMPLER
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary ya water
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        // visited mark
        grid[i][j] = 0;

        // current cell = 1
        int area = 1;

        // 4 directions
        area += dfs(i + 1, j, grid);
        area += dfs(i - 1, j, grid);
        area += dfs(i, j + 1, grid);
        area += dfs(i, j - 1, grid);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
}; */