class Solution {

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, int> mp; // idx --> dist

        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0] * points[i][0] +
                       points[i][1] * points[i][1]; // comparison will be same without sqrt as sqrt(x) < sqrt(y) agarx < y so for optimization not taking sqrt
            mp[i] = dist;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater <pair<int,int>>> pq; // {dist, idx}
        for(auto it : mp){
            pq.push({it.second, it.first}); // distance ke acc idx pq mein gaye
        }

        vector<vector<int>> ans; // final ans
        for(int i = 0; i < k; i++){
            int idx = pq.top().second; // idx liya
            pq.pop();
            ans.push_back(points[idx]); // values nikali at that idx
        }
        return ans;

    }
};