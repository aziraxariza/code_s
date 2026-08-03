class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; //max heap banaya
        for(int x : nums){ // push all eles in heap
            pq.push(x);
        }
        int ans = 0;
        for(int i = 0; i < k; i++){
            ans = pq.top(); // k times to get top kth
            pq.pop();
        }
        return ans;
    }
};