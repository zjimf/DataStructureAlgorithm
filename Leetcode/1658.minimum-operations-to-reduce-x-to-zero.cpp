/** 1658. Minimum Operations to Reduce X to Zero
 *  @brief 因為找兩端太難設計，故換一種想法，在nums中找可以形成sum-x(target)之最長的subArray。
 *         雙指標，right做為右指標持續推進
 *         遍歷整個nums，以right推進，若是目前curSum的值已經大於target為left前進的條件
 *         得注意left不得超過right
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int target = 0, n = nums.size();

        for (auto n : nums)
            target += n;

        target -= x;

        if (target == 0)
            return n;

        int curSum = 0, left = 0, res = 0;

        for (int right = 0; right < n; right++) {
            curSum += nums[right];

            while (left <= right && curSum > target)
                curSum -= nums[left++];

            if (curSum == target)
                res = max(res, right - left + 1);
        }

        return res ? n - res : -1;
    }
};
// @lc code=end
