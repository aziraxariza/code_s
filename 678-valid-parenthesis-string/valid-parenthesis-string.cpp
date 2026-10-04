class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for(char c : s){
            if(c == '('){
                minOpen++;
                maxOpen++;
            }
            else if(c == ')'){
                minOpen--;
                maxOpen--;
            }
            else { // case for '*'
                minOpen--;      // treat as ')'
                maxOpen++;      // treat as '('
            }

            if(maxOpen < 0) return false; // too many ')' the input mein --> agar max hi -ve hai what's the point of continuing?
            minOpen = max(minOpen, 0);   // to find if '(' ke sare khatam ya left (if left then invalid)
        }

        return minOpen == 0;
    }
};
