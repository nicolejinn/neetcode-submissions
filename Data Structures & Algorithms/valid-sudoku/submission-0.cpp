class Solution {
    // 1, 2, 3
    // 4, 5, 6
    // 7, 8, 9
    int getSubBox(int row, int col) {
        return (row/3)*3 + col/3;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1st 81 entries: 9 digits across 9 rows
        // 2nd 81 entries: 9 digits across 9 cols
        // 3rd 81 entries: 9 digits across 9 sub-boxes
        vector<bool> is_digit_on_board(243, false);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // row i, col j
                char c = board[i][j];
                if (c == '.') continue;

                int digit = c - '0';
                int b = getSubBox(i, j);
                vector<int> idxs {
                    /*row check =*/ i*9 + digit,
                    /*col check =*/ 81 + j*9 + digit,
                    /*box check =*/ 162 + b*9 + digit
                };
                for (const int idx : idxs) {
                    if (is_digit_on_board[idx]) return false;
                    is_digit_on_board[idx] = true;
                }
            }
        }
        return true;
    }
};
