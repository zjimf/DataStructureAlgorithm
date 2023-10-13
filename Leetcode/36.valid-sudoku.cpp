/** 36. Valid Sudoku
 *  每新的回合創立新的hashmap檢查row, column是否有重複的，若到(0,0)(0,3)(0,6)(3,0)(3,3)(3,6)(6,0)(6,3)(6,6)則檢查九宮格
 *
 *  @Time_complexity O(N^2)
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            unordered_set<char> column;
            for (int j = 0; j < 9; j++) {
                // row
                if (row.count(board[i][j]))
                    return false;
                if (board[i][j] != '.')
                    row.insert(board[i][j]);

                // column
                if (column.count(board[j][i]))
                    return false;
                if (board[j][i] != '.')
                    column.insert(board[j][i]);

                // grid
                if ((i == 0 || i == 3 || i == 6) && (j == 0 || j == 3 || j == 6)) {
                    unordered_set<char> grid;
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++) {
                            if (grid.count(board[k + i][l + j]))
                                return false;

                            if (board[k + i][l + j] != '.')
                                grid.insert(board[k + i][l + j]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
