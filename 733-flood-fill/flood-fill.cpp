class Solution {
public:        
    void dfs(int i, int j, vector<vector<int>>& image, int color, int beg, vector<vector<int>>& vis){
        int m = image.size();
        int n = image[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != beg || vis[i][j] == 1) return; // out of bounds to be updated

        vis[i][j] = 1; // mark visited
        image[i][j] = color; // update color

        dfs(i+1, j, image, color, beg, vis);
        dfs(i-1, j, image, color, beg, vis);
        dfs(i, j+1, image, color, beg, vis);
        dfs(i, j-1, image, color, beg, vis);

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); // rows
        int n = image[0].size(); // cols

        int beg = image[sr][sc]; // save kiya jinhe change karenge

        vector<vector<int>> vis(m, vector<int>(n, 0)); // to keep track of visited ones

        dfs(sr, sc, image, color, beg, vis);// call dfs yaha se

        return image;
    }
};