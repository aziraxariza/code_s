class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;

        char ans = letters[0];
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(letters[mid] > target){
                ans = letters[mid];
                hi = mid - 1; // isse chhote dekho ki koi aur hai jo target se bada ho
            }
            else{
                lo = mid + 1; // since target se ye chhota tha iske aage se dekho koi bada 
            }
        }
        return ans;
    }
};