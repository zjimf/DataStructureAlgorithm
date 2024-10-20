/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        find(candidates, target, 0, 0, sub, res);

        return res;
    }

    void find(vector<int> &candidates, int target, int idx, int total, vector<int> &sub, vector<vector<int>> &res) {
        if (total == target) {
            res.push_back(sub);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        sub.push_back(candidates[idx]);
        find(candidates, target, idx, total + candidates[idx], sub, res);
        sub.pop_back();
        find(candidates, target, idx + 1, total, sub, res);
    }
};
// @lc code=end
