/** 54. Spiral Matrix
 *  @brief using four limit u,d,l,r to shrink the output circle
 *
 *  @Time_complexity O(matrix size)
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, u = 0, d = m - 1, l = 0, r = n - 1, p = 0;
        vector<int> order(m * n);
        while (u <= d && l <= r) {
            for (int col = l; col <= r; col++) {
                order[p++] = matrix[u][col];
            }
            if (++u > d) {
                break;
            }
            for (int row = u; row <= d; row++) {
                order[p++] = matrix[row][r];
            }
            if (--r < l) {
                break;
            }
            for (int col = r; col >= l; col--) {
                order[p++] = matrix[d][col];
            }
            if (--d < u) {
                break;
            }
            for (int row = d; row >= u; row--) {
                order[p++] = matrix[row][l];
            }
            if (l++ > r) {
                break;
            }
        }
        return order;
    }
};
/** 54. Spiral Matrix
 *  @brief Use a way similar to Circular Array to change the direction
 *
 *  @Time_complexity O(matrix size)
 */
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>> &matrix) {
//         vector<int> output;
//         vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0, breads = 0, currentDirection = 0;
//         while (breads < m * n) {
//             breads++;
//             output.push_back(matrix[i][j]);
//             matrix[i][j] = -999;

//             int next_i = i + directions[currentDirection][0];
//             int next_j = j + directions[currentDirection][1];

//             if (next_i == m || next_i == -1 || next_j == n || next_j == -1 || matrix[next_i][next_j] == -999) {
//                 currentDirection = (currentDirection + 1) % 4;
//                 next_i = i + directions[currentDirection][0];
//                 next_j = j + directions[currentDirection][1];
//             }

//             i = next_i;
//             j = next_j;
//         }
//         return output;
//     }
// };
