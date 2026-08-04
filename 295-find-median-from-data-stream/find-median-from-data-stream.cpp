class MedianFinder {
public:
    priority_queue<int> left; // max heap --> chhote eles rakhega but bada faikega right mein
    priority_queue<int, vector<int>, greater<int>> right; // min heap --> bade elements rakhega 
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num); // left mein dala pehle
        right.push(left.top()); // left ka sabse bada right mein
        left.pop(); // jo dala usse nikala

        if(right.size() > left.size()){ // right mein zyada ho gaye --> not possibel
            left.push(right.top()); // right ka sabse chhota left mein dala
            right.pop(); // right mein dala
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){ // odd eles
            return left.top();
        }
        return (left.top()+right.top())/2.0; // even eles (humesha float)
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */