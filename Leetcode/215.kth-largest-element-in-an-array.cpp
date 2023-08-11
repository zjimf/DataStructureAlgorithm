/** 215. Kth Largest Element in an Array
 * @brief using quicksort partition method
 *
 * Time_complexity O(nlogn) but might O(n^2)
 */
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return partition(nums, 0, nums.size() - 1, k);
    }

private:
    int partition(vector<int> nums, int left, int right, int k) {
        int pivot = nums[right];
        int j = left - 1;
        for (int i = left; i < right; i++)
            if (nums[i] >= pivot)
                swap(nums[i], nums[++j]);

        swap(nums[++j], nums[right]);
        if (j == k - 1)
            return nums[j];
        else if (j < k - 1)
            return partition(nums, j + 1, right, k);
        else
            return partition(nums, left, j - 1, k);
    }
};
