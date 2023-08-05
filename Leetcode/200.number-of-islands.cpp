/** 200. Number of Islands
 *  @brief BFS、DFS
 *
 *  @Time_complexity O(M*N) M:column nums N:row nums
 */
class Solution {
public:
    // BFS
    int numIslands(vector<vector<char>> &grid) {
        int island = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {

                    grid[i][j] = '0';
                    island++;

                    queue<pair<int, int>> queue;
                    queue.push({i, j});
                    while (!queue.empty()) {
                        pair<int, int> p = queue.front();
                        queue.pop();

                        //{0,1},{1,0},{0,-1},{-1,0}
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                queue.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return island;
    };

    // int numIslandsDFS(vector<vector<char>> &grid) {
    //     int island = 0;
    //     for (int i = 0; i < grid.size(); i++)
    //         for (int j = 0; j < grid[0].size(); j++)
    //             if (grid[i][j] == '1') {
    //                 dfs(grid, i, j);
    //                 island++;
    //             }

    //     return island;
    // }

    // private:
    //     void dfs(vector<vector<char>> &grid, const int &i, const int &j) {
    //         if (grid[i][j] == '0')
    //             return;

    //         grid[i][j] = '0';
    //         if (i - 1 >= 0)
    //             dfs(grid, i - 1, j);
    //         if (i + 1 < grid.size())
    //             dfs(grid, i + 1, j);
    //         if (j - 1 >= 0)
    //             dfs(grid, i, j - 1);
    //         if (j + 1 < grid[0].size())
    //             dfs(grid, i, j + 1);
    //     }
};
