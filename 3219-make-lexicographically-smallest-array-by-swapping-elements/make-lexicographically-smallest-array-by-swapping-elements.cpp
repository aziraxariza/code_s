class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        vector<pair<int,int>> a;

        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        for(int i = 0; i < n; ) {
            int j = i;

            // ek connected group find karo
            while(j + 1 < n && a[j + 1].first - a[j].first <= limit)
                j++;

            // original indices sort karo
            vector<int> idx;
            for(int k = i; k <= j; k++)
                idx.push_back(a[k].second);

            sort(idx.begin(), idx.end());

            for(int k = 0; k < idx.size(); k++) // smallest values -> smallest indices
                nums[idx[k]] = a[i + k].first;

            i = j + 1;
        }
        return nums;
    }
};