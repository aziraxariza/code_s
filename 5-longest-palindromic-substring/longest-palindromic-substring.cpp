class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        if(n == 0) return ""; 

        int start = 0; // start index of longest palindrome
        int maxLen = 1; // kyuki every single character is a palindrome

        for(int i = 0; i < n; i++) { // try every index as a center

            int l = i, r = i; // odd length palindrome center at i
            while(l >= 0 && r < n && s[l] == s[r]) { // expand while characters match
                if(r - l + 1 > maxLen) { // found a longer palindrome
                    maxLen = r - l + 1; // update maximum length
                    start = l; // update starting index
                }
                l--; 
                r++; 
            }

            l = i, r = i + 1; // even length palindrome center between i and i+1
            while(l >= 0 && r < n && s[l] == s[r]) { // expand while characters match
                if(r - l + 1 > maxLen) { // found a longer palindrome
                    maxLen = r - l + 1; // update maximum length
                    start = l; // update starting index
                }
                l--; 
                r++; 
            }
        }

        return s.substr(start, maxLen); // return longest palindromic substring
    }
};