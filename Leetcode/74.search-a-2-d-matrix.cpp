class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int column = n - 1;

        for (int row = 0; row < m; row++) {
            if (target > matrix[row][column])
                continue;

            int left = row * n;
            int right = left + n - 1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (matrix[mid / n][mid % n] == target)
                    return true;
                else if (target < matrix[mid / n][mid % n])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};
