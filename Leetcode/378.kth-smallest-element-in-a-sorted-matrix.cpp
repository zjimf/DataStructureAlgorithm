/** 378. Kth Smallest Element in a Sorted Matrix
 * @brief maxHeap
 *
 * Time_complexity O(N*logN)
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (k == 1)
            return matrix[0][0];
        priority_queue<int> maxHeap;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxHeap.push(matrix[i][j]);

                if (maxHeap.size() > k)
                    maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
