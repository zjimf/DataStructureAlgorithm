/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> targetMap;
        if (s1.length() > s2.length())
            return false;

        int slidingWinLen = s1.length();

        for (auto c : s1)
            targetMap[c]++;

        for (int left = 0; left <= s2.length() - slidingWinLen + 1; left++) {
            bool res = true;
            unordered_map<char, int> tempMap;
            for (int right = 0; right < slidingWinLen; right++) {
                tempMap[s2[left + right]]++;
            }

            for (auto temp : tempMap) {
                if (tempMap[temp.first] != targetMap[temp.first]) {
                    res = false;
                    break;
                }
            }
            if (res)
                return true;
        }
        return false;
    }
};
// @lc code=end
