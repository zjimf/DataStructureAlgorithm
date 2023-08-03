/** 59. Spiral Matrix II
 *  @brief Use a way similar to Circular Array to change the direction
 *
 *  @Time_complexity O(N*N)
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0, j = 0, currentVal = 1, currentDir = 0;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (currentVal <= n * n) {
            arr[i][j] = currentVal++;

            int next_i = i + directions[currentDir][0];
            int next_j = j + directions[currentDir][1];

            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n || arr[next_i][next_j] != 0) {
                currentDir = (currentDir + 1) % 4;
                next_i = i + directions[currentDir][0];
                next_j = j + directions[currentDir][1];
            }

            i = next_i;
            j = next_j;
        }

        return arr;
    }
};
