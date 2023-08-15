/** 15. 3Sum
 *  @brief Using three pointer
 *         Iterate nums with variable i, and calculate target(0-nums[i])
 *         left point to i+1, right point to len-1
 *         check left + right whether equal target, if not, move the left or right
 *
 *  @Time_complexity O(N^2)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            // speed up, if i is the same as previous round
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int leftPlusRight = nums[left] + nums[right];
                if (leftPlusRight == target) {
                    ans.push_back({nums[i], nums[left++], nums[right]});
                } else if (leftPlusRight < target) {
                    left++;
                } else {
                    right--;
                    continue;
                }
                // speed up, if left is the same as previous round
                while (left < right && nums[left] == nums[left - 1])
                    left++;
            }
        }
        return ans;
    }
};
