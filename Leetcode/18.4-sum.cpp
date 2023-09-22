/** 18. 4Sum
 *  @brief 使用四個pointer
 *         每次鎖定兩個點，並選取目前該元素(j)的下一個作為left指標，陣列尾端為right指標
 *         每輪讓left和right彼此靠近確定加總是否等於target-（nums[i]+nums[j]）即可
 *         但因有一test case可能造成overflow, 故要使用long long
 *
 *  @Time_complexity O(N^2)
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = n - 1;
                // test case may overflow
                long long currentTarget = (long long)target - ((long long)nums[i] + (long long)nums[j]);

                while (left < right) {
                    if (nums[left] + nums[right] == currentTarget) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    } else if (nums[left] + nums[right] < currentTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
