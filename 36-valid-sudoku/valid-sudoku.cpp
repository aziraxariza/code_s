class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9); // all 9 rows as sets for cchecking .count() se ki iss row mwin hai kya alr [{}, {}, {}, ..] 9 such sets for each row
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9); // 9 3x3 boxes ke liye

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue; // '.' matter nhi karta

                char num = board[i][j]; // num kya hai
                int box = 3*(i/3) + (j/3); // kaunse box mein hai acc. to its i j

                if(rows[i].count(num) || cols[j].count(num) || boxes[box].count(num)){
                    return false; // alr same row/col/box mein hai ye num
                }
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num); // dalo uske i j and box mein usse
            }
        }
        return true;
    }
};