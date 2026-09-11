class Solution {
public:
    bool isPalindrome(int x) {
       vector<int> check; // digis store

       if(x < 0) return false;

       while(x > 0){
        check.push_back(x%10);
        x /= 10;
       }
       int l = 0;
       int r = check.size()-1;

       while(l < r){
        if(check[l] != check[r]) return false;
        l++;
        r--;
       }
       return true;
    }
};
