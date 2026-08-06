class Solution {
public:
    int productOfDigits(int num){
        int product = 1;

        while(num){ // har ek remainder ko le kar multiply
            product *= num % 10;
            num /= 10; // update num
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        while(productOfDigits(n) % t != 0) // check if product of digits is divisible by t
            n++; // agar nahi toh n ko increment karo
        return n;
    }
};