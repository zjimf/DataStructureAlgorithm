
// @lc code=start

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> results(temperatures.size());
        stack<int> stack;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                results[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        return results;
    }
};
// @lc code=end

// @lc code=start
// TLE
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures) {
//         vector<int> result;
//         for (int i = 0; i < temperatures.size() - 1; i++) {
//             int j = 1;
//             while (temperatures[i] >= temperatures[i + j]) {
//                 j++;
//                 if (i + j == temperatures.size()) {
//                     j = 0;
//                     break;
//                 }
//             }
//             result.push_back(j);
//         }
//         result.push_back(0);
//         return result;
//     }
// };
