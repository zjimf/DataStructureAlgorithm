/** 34. Find First and Last Position of Element in Sorted Array
 *  @brief binary search find the target, then Spread out from that point
 *
 *  @Time_complexity O(logN), O(N) if all elements is same
 */
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid;
                right = mid;
                break;
            }
        }
        if (left > right)
            return {-1, -1};

        while (left != 0 && nums[left - 1] == target)
            left--;

        while (right != nums.size() - 1 && nums[right + 1] == target)
            right++;

        return {left, right};
    }
};
