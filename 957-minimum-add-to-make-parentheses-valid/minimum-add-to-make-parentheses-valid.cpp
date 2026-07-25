class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int add = 0;

        for (char ch : s) {
            if (ch == '(') { // '(' open mein dalo
                open++;
            } else {
                if (open > 0) // agar ( present hai toh ')' ke acc kum karo
                    open--;
                else // no more '(' left
                    add++; // baaki ')' ko alag mein store karo
            }
        }

        return add + open; // jitne akele bach gaye unko complete karne ke liye
    }
};