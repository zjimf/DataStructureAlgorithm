/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> hashMap;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++){
            if(hashMap.find(target-numbers[i])!=hashMap.end()) {
                result.push_back(hashMap[target-numbers[i]]);
                result.push_back(i+1);
            }else{
                hashMap[numbers[i]] = i+1;
            }
        }
        return result;
    }
};
// @lc code=end
