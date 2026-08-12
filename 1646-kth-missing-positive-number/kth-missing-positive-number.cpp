class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> miss;
        unordered_set<int> s(arr.begin(), arr.end());

        int n = arr.size();
        for(int i = 1; i <= arr[n-1] + k; i++){
            if(!s.count(i)){
                miss.push_back(i);

            }
        }

        return miss[k-1];
    }
};