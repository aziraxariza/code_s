class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // rows total
        int n = matrix[0].size(); // total cols

        for(int i = 0; i < m; i++){ // har row ke liye bs karenge jab tak na mile
            int l = 0; // initial col posn
            int r = n-1; // last col posn

            while(l <= r){
                int mid = l + (r-l)/2; // mid col idx

                if(matrix[i][mid] == target) return true; // mil gaya

                else if(matrix[i][mid] > target){
                    r = mid-1; // iske peeche ho sakta hai since isse chhota hai
                }

                else{
                    l = mid+1; // iske aage maybe
                }
                // agar nahi mila toh for loop se row next i ki value hogi
            }
        }
        return false;
    }
};