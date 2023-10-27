/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        if (n < 10)
            return ans;

        unordered_map<string, int> map;
        for (int i = 0; i < s.size() - 9; i++)
            map[s.substr(i, 10)]++;

        for (auto item : map)
            if (item.second > 1)
                ans.push_back(item.first);

        return ans;
    }
};
// @lc code=end
