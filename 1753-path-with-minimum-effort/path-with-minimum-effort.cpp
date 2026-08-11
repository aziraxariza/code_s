class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); //sabka dist inf kiya

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq; // {effort, row, col}

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1}; // all 4 dirxns

        while(!pq.empty()) {

            auto [effort, r, c] = pq.top(); // top liya
            pq.pop();

            if(effort > dist[r][c]) continue; // aagr effort zyada hai toh rehne do

            if(r == n-1 && c == m-1) // last row col mein hai
                return effort; // return kardo effort accumulated

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i]; // row col adj to r c

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue; // out of bounds

                int diff = abs(heights[r][c] - heights[nr][nc]);

                int newEffort = max(effort, diff);

                if(newEffort < dist[nr][nc]) {

                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0;
    }
};