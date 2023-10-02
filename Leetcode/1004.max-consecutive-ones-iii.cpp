/** 1004. Max Consecutive Ones III
 *  @brief 雙指標，fast持續前進，遇到0時count--
 *                當count<0（已無替換扣打），slow前進，count++
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int count = k;
        int slow = 0, fast = 0;

        while (fast < nums.size()) {
            if (nums[fast] == 0)
                count--;

            if (count < 0) {
                if (nums[slow] == 0)
                    count++;
                slow++;
            }
            fast++;
        }
        return fast - slow;
    }
};
