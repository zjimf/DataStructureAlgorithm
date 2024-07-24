/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low!=high){
            int mid = (low+high)/2;
            if(nums[mid]<nums[high]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return nums[low];
    }
};
// @lc code=end
