class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        queue<pair<int, int>> q; // {i, j} of 0s
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < m; i++){ // us poori col ko 0
                matrix[i][c] = 0;
            }
            for(int j = 0; j < n; j++){ // us poori row ko zero
                matrix[r][j] = 0;
            }
        }
    }
};