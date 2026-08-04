class KthLargest {
public:
    // define min heap here not in constructor and k too taki its accesible in complete class
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    // this is constructor
    KthLargest(int k, vector<int>& nums){
        this->k = k;
        for(int x : nums){
            pq.push(x); // min heap mein dalo

            if(pq.size() > k){// size exceeded after addition
                pq.pop(); // sabse min hata do kyuki sirf k largest rakhne hai hume
            }
        }
    }

    int add(int val){
        pq.push(val);
        if(pq.size() > k){
            pq.pop(); // sirf k elements rakhenge aur front kth largets hoga regardless of adding val
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */