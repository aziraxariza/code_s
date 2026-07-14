class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> mp;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (++mp[board[i][j]] > 1) return false;
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_map<char, int> mp;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (++mp[board[i][j]] > 1) return false;
            }
        }

        // Check 3x3 boxes
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                unordered_map<char, int> mp;

                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {

                        if (board[i][j] == '.') continue;
                        if (++mp[board[i][j]] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};