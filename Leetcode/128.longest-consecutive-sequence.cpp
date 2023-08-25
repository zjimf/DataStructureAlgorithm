/** 128. Longest Consecutive Sequence
 *  @brief Unordered_set find the leftmost number, then +1 find the rightmost number
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int global = 0;
        for (int n : nums) {
            if (set.count(n - 1))
                continue;
            int local = 1;
            while (set.count(++n))
                local++;
            global = max(global, local);
        }
        return global;
    }
};

/** 128. Longest Consecutive Sequence
 *  @brief Unordered_map find the leftmost number, then +1 find the rightmost number
 *
 *  @Time_complexity O(N)
 */
// class Solution {
// public:
//     int longestConsecutive(vector<int> &nums) {
//         unordered_map<int, int> map;
//         for (auto n : nums)
//             map[n] = true;

//         for (auto n : nums)
//             if (map.count(n + 1)) {
//                 map[n + 1] = false;
//             }

//         int ans = 0;
//         for (auto n : nums) {
//             int i = 1, localAns = 1;
//             if (map[n]) {
//                 while (map.count(n + i)) {
//                     i++;
//                     localAns++;
//                 }
//             }
//             ans = localAns > ans ? localAns : ans;
//         }
//         return ans;
//     }
// };
