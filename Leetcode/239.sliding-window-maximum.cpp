/**
 * @brief deque
 *
 * Time_complexity O(n)
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> w;
        for (int i = 0, n = (int)nums.size(); i < n; i++) {
            // 確保長度為k
            while (!w.empty() && w.front() <= i - k)
                w.pop_front();
            // 要塞入值時，確認最後的值是否有比自己大，如此能保證w都是sorted(decreased)的狀態
            while (!w.empty() && nums[w.back()] <= nums[i])
                w.pop_back();
            w.push_back(i);
            if (i >= k - 1)
                result.push_back(nums[w.front()]);
        }
        return result;
    }
};

/**
 * @brief Priority queue
 *        the size in pq is not the important thing, because we will store the index in qp
 *        So we can know whether the current top value has been slid over.
 *
 * Time_complexity O(n log n)
 */
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k) {
//         priority_queue<pair<int, int>> pq;
//         vector<int> ans;
//         int len = nums.size();
//         for (int i = 0; i < k; i++)
//             pq.push({nums[i], i});

//         ans.push_back(pq.top().first);
//         for (int i = k; i < len; i++) {
//             while (!pq.empty() && pq.top().second <= i - k)
//                 pq.pop();

//             pq.push({nums[i], i});
//             ans.push_back(pq.top().first);
//         }
//         return ans;
//     }
// };

/**
 * @brief Multiset
 *        hold the size in k, and multiset's elements will be sorted
 *        so, We just need to delete the value sliding out of the window, add the value sliding into the window
 *
 * Time_complexity O(n log k)
 */
//   class Solution {
//   public:
//       vector<int> maxSlidingWindow(vector<int> &nums, int k) {
//           multiset<int> m;
//           vector<int> v;
//           int len = nums.size(), left = 0;
//           for (int right = 0; right < len; right++) {
//               m.insert(nums[right]);
//               if (right >= k - 1) {
//                   v.push_back(*m.rbegin());
//                   m.erase(m.find(nums[left++]));
//               }
//           }
//           return v;
//       }
//   };
