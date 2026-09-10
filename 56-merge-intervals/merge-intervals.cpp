class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // final ans;

        sort(intervals.begin(), intervals.end()); // start time ke acc sort
        ans.push_back(intervals[0]); // sabse first start time wala ans mein first ele

        for(int r = 1; r < intervals.size(); r++){

            if(intervals[r][0] <= ans.back()[1]){ // agar iska start last ke end se pehle
                ans.back()[1] = max(ans.back()[1], intervals[r][1]); // end time is max of the two
            }
            else{
                ans.push_back(intervals[r]);
            }
        }
        return ans;
    }
};