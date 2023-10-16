/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string> &words) {
        int n = words.size();
        vector<int> v;

        // a -> 0001
        // b -> 0010
        // c -> 0100
        // d -> 1000

        // ac -> 0101
        // bd -> 1010
        // ac & bd -> 0000

        for (int i = 0; i < n; i++) {
            int wToBinary = 0;
            for (int j = 0; j < words[i].size(); j++) {
                wToBinary |= 1 << (words[i][j] - 'a');
            }
            v.push_back(wToBinary);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((v[i] & v[j]) == 0) {
                    int prod = words[i].size() * words[j].size();
                    res = max(res, prod);
                }
            }
        }
        return res;
    }
};
