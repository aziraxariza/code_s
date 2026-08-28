class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0;
        int hi = arr.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int missing = arr[mid] - (mid + 1); // kitne no. missing hai apni position se

            if(missing < k){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo + k; // ans se pehle existing no.s + kth from it
    }
};
    

/*vector<int> miss;  {THIS IS O(N) ans}
        unordered_set<int> s(arr.begin(), arr.end());

        int n = arr.size();
        for(int i = 1; i <= arr[n-1] + k; i++){
            if(!s.count(i)){
                miss.push_back(i);

            }
        }

        return miss[k-1]; */