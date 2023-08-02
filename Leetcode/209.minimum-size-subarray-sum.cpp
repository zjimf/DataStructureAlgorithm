/** 209. Minimum Size Subarray Sum
 *  @brief just like sliding window
 *
 *  @Time_complexity O(2N)
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ans = INT_MAX, left = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
