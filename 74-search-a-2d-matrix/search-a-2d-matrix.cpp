class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // rows 
        int n = matrix[0].size(); // cols
        
        int l = 0; // if flatten then first idx
        int r = m*n - 1; // if flatten last idx

        while(l <= r){
            int mid = l + (r-l)/ 2; // mid idx when flattened

            // mid ele location in matrix
            int row = mid / n; // mid idx divided by totals cols gives row no.
            int col = mid % n; // mid mod no. of total cols gives col no. 

            if(matrix[row][col] == target) return true; // mil gaya 

            else if(matrix[row][col] > target){
                r = mid - 1; // mid ke peeche hai 
            }
            else{
                l = mid + 1;
            }
        }
        return false; // default ans
    }
};