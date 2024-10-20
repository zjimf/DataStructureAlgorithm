/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> sub;

        traverse(nums, sub, 0, res);

        return res;
    }

    void traverse(vector<int> &nums, vector<int> &sub, int current, vector<vector<int>> &res) {
        res.push_back(sub);

        for (int i = current; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            traverse(nums, sub, i + 1, res);
            sub.pop_back();
        }
    }
};
// @lc code=end
