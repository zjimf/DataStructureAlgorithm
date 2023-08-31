/** 973. K Closest Points to Origin
 *  @brief max heap
 *
 *  @Time_complexity O(N * Log(N))
 */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < points.size(); i++)
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            vector<int> top = pq.top();
            pq.pop();
            ans.push_back(points[top[1]]);
        }
        return ans;
    }
};
