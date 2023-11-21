/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;

    bool is_valid(vector<string> &board, int row, int col) {
        for (int i = row; i >= 0; --i)
            if (board[i][col] == 'Q')
                return false;
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q')
                return false;
        for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }

    void dfs(vector<string> &board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); ++col) {
            if (is_valid(board, row, col)) {
                // setting
                board[row][col] = 'Q';
                // find next
                dfs(board, row + 1);
                // backtracking
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0)
            return {{}};

        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return res;
    }
};
// @lc code=end
