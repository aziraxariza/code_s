class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(auto x : intervals) {
            if(ans.empty()) { // pehla interval
                ans.push_back(x); // daal diya ans mein
            }

            else if(x[0] <= ans.back()[1]) { // overlap hai
                ans.back()[1] = max(ans.back()[1], x[1]); // last ka [1] update kiya bigger val se
            }

            else { // overlap nahi hai
                ans.push_back(x);
            }
        }
        return ans;
    }
};