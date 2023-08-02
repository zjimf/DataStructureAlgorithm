/** 1. Two Sum
 *  @brief Using unordered_map(hash)
 *         if found (target-current) in the map return the pair index,
 *         else store in map {current value, current index}
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end())
                return {map[target - nums[i]], i};
            // not found
            map[nums[i]] = i;
        }
        return {};
    }
};