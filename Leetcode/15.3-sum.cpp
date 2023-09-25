/** 15. 3Sum
 *  @brief 使用三個pointer
 *         遍歷每個陣列的元素，並選取目前該元素的下一個作為left指標，陣列尾端為right指標
 *         每輪讓left和right彼此靠近確定加總是否等於（-nums[i]）即可
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
