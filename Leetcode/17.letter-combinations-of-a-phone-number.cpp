/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letter{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        string path = "";
        DFS(digits, 0, path, res);
        return res;
    }

private:
    void DFS(string digits, int pos, string &path, vector<string> &res) {
        if (pos == digits.size()) {
            res.push_back(path);
            return;
        }

        for (auto c : letter[digits[pos] - '0']) {
            path.push_back(c);
            DFS(digits, pos + 1, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end
