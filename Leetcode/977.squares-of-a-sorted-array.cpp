/** 977. Squares of a Sorted Array
 *  @brief Squares all element, stored in new vector, sorting
 *
 *  @Time_complexity O(NlogN)
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> newVec;
        for (auto &n : nums) {
            newVec.push_back(n * n);
        }
        sort(newVec.begin(), newVec.end());
        return newVec;
    }
};
