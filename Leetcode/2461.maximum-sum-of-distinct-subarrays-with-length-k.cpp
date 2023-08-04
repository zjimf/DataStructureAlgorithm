/** 2461. Maximum Sum of Distinct Subarrays With Length K
 *  @brief sliding window
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        long long int local_max = 0, global_max = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (!umap.count(nums[i]))
                local_max += nums[i];
            umap[nums[i]]++;
            if (umap.size() == k)
                global_max = max(local_max, global_max);

            if (i - k + 1 >= 0) {
                umap[nums[i - k + 1]]--;
                if (umap[nums[i - k + 1]] == 0) {
                    local_max -= nums[i - k + 1];
                    umap.erase(nums[i - k + 1]);
                }
            }
        }
        return global_max;
    }
};
// time limited
// long long maximumSubarraySum(vector<int> &nums, int k) {
//     int global_max = 0;
//     for (int i = 0; i <= nums.size() - k; i++) {
//         unordered_set<int> set;
//         int local_max = 0;
//         for (int j = 0; j < k; j++) {
//             if (set.count(nums[i + j])) {
//                 local_max = 0;
//                 break;
//             }
//             set.insert(nums[i + j]);
//             local_max += nums[i + j];
//         }
//         global_max = max(global_max, local_max);
//     }
//     return global_max;
// }