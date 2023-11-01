/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;

        priority_queue<pair<int, char>> maxHeap;
        for (auto m : map)
            maxHeap.push({m.second, m.first});

        int size = maxHeap.size();
        string ans = "";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < maxHeap.top().first; j++)
                ans += maxHeap.top().second;
            maxHeap.pop();
        }

        return ans;
    }
};
// @lc code=end
