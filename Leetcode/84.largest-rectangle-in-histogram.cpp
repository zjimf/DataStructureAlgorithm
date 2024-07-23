/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> stack;
        stack.push(-1);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            // 當目前的方塊已經無法再延伸，也就是已經下滑，
            // 就要將比自己大的pop出去，並逐一計算pop出去計算大小
            while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                max_area = max(max_area, height * width);
            }
            stack.push(i);
        }

        // 計算留在stack中的
        while (stack.top() != -1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = heights.size() - stack.top() - 1;
            max_area = max(max_area, height * width);
        }

        return max_area;
    }
};
// @lc code=end
