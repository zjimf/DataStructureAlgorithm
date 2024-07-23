/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int totalProduct = 1;
        int zeroCount = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                totalProduct *= nums[i];
            } else {
                zeroCount++;
            }
        }
        
        if (zeroCount > 1) {
            fill(result.begin(), result.end(), 0);
        } else if (zeroCount == 1) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) {
                    result[i] = totalProduct;
                } else {
                    result[i] = 0;
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                result[i] = totalProduct / nums[i];
            }
        }
        
        return result;
    }
};
// @lc code=end