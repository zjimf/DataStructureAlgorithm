/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> visited;
        queue<int> queue;
        visited.insert(0);
        queue.push(0);
        int steps = 0;

        while (!queue.empty()) {
            ++steps;

            for (int i = queue.size() - 1; i >= 0; i--) {
                int front = queue.front();
                queue.pop();

                for (int j = 1; j * j <= n; j++) {
                    int current = front + j * j;

                    if (current == n)
                        return steps;

                    if (!visited.count(current)) {
                        visited.insert(current);
                        queue.push(current);
                    }
                }
            }
        }
        return steps;
    }
};
