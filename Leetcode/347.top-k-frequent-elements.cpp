/** 347. Top K Frequent Elements
 * @brief maxHeap, unordered_map(count)
 *
 * Time_complexity O(N*logN)
 */
#define pii pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        priority_queue<pii> maxHeap;
        unordered_map<int, int> map;
        vector<int> v;

        if (nums.size() == 1)
            return nums;

        for (auto n : nums)
            map[n]++;

        for (auto m : map) {
            maxHeap.push({m.second, m.first});
            if (maxHeap.size() > map.size() - k) {
                v.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }

        return v;
    }
};
