/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int currentArea = (right - left) * min(height[right], height[left]);
            maxArea = max(maxArea, currentArea);

            if (height[right] < height[left]) {
                right--;
            } else {
                left++;
            }
        }
        return maxArea;
    }
};
// @lc code=end
