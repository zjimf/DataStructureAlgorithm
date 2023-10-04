/** 1658. Minimum Operations to Reduce X to Zero
 *  @brief 因為找兩端太難設計，故換一種想法，在nums中找可以形成sum-x(target)之最長的subArray。
 *         類似雙指標，i做為右指標持續推進，而左指標紀錄在map中。
 *         遍歷整個nums，以i推進，每次紀錄<目前的sum,目前的i>，為了紀錄左邊方塊的大小。
 *         每次看sum-target是否存在map中，若有，表示符合subArray，無則表示需繼續。
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int target = 0, n = nums.size();

        for (auto n : nums)
            target += n;

        if (target == x)
            return n;

        unordered_map<int, int> map;
        map[0] = -1;
        target -= x;
        int sum = 0;
        int res = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (map.count(sum - target)) {
                res = max(res, i - map[sum - target]);
            }

            map[sum] = i;
        }
        return res == INT_MIN ? -1 : n - res;
    }
};
// @lc code=end
