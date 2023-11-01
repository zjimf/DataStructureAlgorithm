/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;

        for (auto t : tasks)
            map[t]++;

        for (auto m : map)
            pq.push({m.second, m.first});

        int ans = 0;
        while (pq.size() > 0) {
            if (pq.top().first == 1) {
                ans += pq.size();
                break;
            }

            vector<pair<int, char>> temp;
            temp.push_back(pq.top());
            pq.pop();
            ans++;
            for (int i = 0; i < n; i++) {
                if (pq.size() > 0) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                ans++;
            }
            for (auto x : temp)
                if (x.first > 1)
                    pq.push({x.first - 1, x.second});
        }
        return ans;
    }
};
// @lc code=end
