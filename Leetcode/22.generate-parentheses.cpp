/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }

    void dfs(int left, int right, string cur, vector<string> &res) {
        if (left > right)
            return;
        if (left == 0 && right == 0)
            res.push_back(cur);
        else {
            if (left > 0)
                dfs(left - 1, right, cur + "(", res);
            if (right > 0)
                dfs(left, right - 1, cur + ")", res);
        }
    }
};
// @lc code=end
