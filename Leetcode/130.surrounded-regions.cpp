/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    bfs(i, j, m, n, board);
            }
        }
    }

private:
    void bfs(int i, int j, int m, int n, vector<vector<char>> &board) {
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> queue;
        vector<pair<int, int>> flippingRecord;

        visited[i][j] = true;
        flippingRecord.push_back({i, j});
        queue.push({i, j});

        while (!queue.empty()) {
            pair<int, int> pii = queue.front();
            queue.pop();
            for (auto d : direction) {
                int newI = pii.first + d[0], newJ = pii.second + d[1];
                if (newI < 0 || newJ < 0 || newI >= m || newJ >= n) {
                    flippingRecord.clear();
                    while (!queue.empty())
                        queue.pop();
                    break;
                }
                if (board[newI][newJ] == 'O' && !visited[newI][newJ]) {
                    flippingRecord.push_back({newI, newJ});
                    queue.push({newI, newJ});
                    visited[newI][newJ] = true;
                }
            }
        }
        for (auto p : flippingRecord)
            board[p.first][p.second] = 'X';
    }
};
// @lc code=end
