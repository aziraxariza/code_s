class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x : nums){
            pq.push(x);
        }
        int ans = 0;
        for(int i = 0; i < k; i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};