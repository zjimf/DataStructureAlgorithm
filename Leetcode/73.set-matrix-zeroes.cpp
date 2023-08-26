class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        unordered_set<int> setX;
        unordered_set<int> setY;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 0) {
                    setX.insert(i);
                    setY.insert(j);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; j++) {
                if (setX.count(i) || setY.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
