class Solution {
public:        
    void dfs(int i, int j, vector<vector<int>>& image, int color, int ini){
        int m = image.size();
        int n = image[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != ini || image[i][j] == color) return; // agar out of bounds or not same as ini or alr colored

        image[i][j] = color; // mark visited by painting as color
        dfs(i+1, j, image, color, ini); // 4 dirxns
        dfs(i-1, j, image, color, ini);
        dfs(i, j+1, image, color, ini);
        dfs(i, j-1, image, color, ini);

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); // no. of rows
        int n = image[0].size(); // cols

        int ini = image[sr][sc]; // initial color

        dfs(sr, sc, image, color, ini); // yaha se shuruat dfs ko
        
        return image;
    }
};