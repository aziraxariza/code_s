class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int lo = 1;
        int hi = position.back() - position.front();

        int ans = 0;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int balls = 1;
            int last = position[0];

            for(int i = 1; i < position.size(); i++) {

                if(position[i] - last >= mid) {
                    balls++;
                    last = position[i];
                }
            }

            if(balls >= m) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};