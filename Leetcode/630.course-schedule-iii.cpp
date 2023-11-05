/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        int cur = 0;
        priority_queue<int> maxHeap;
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        for (auto &course : courses) {
            cur += course[0];
            maxHeap.push(course[0]);
            if (cur > course[1]) {
                cur -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};
// @lc code=end
