class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversedHalf = 0; // peeche se aadhe number 
        // odd x mein ye beech wala number miss kr dega // even x mein ye aadhe tak  reversed digit dega peeche se

        while(x > reversedHalf){
            reversedHalf = reversedHalf * 10 + x % 10; // making space for last digi of cur x int reverseHalf
            x /= 10; // update x
        }
        
        return (x == reversedHalf || x == reversedHalf/10); // revrsedHalf by 10 se prove hoga jo odd x mein beech ka number hai woh palindrome banayega ya nahi
    }
};

/* 
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
*/