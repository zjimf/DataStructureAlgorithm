// Multiset, sliding window
class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        multiset<int> m;
        int left = 0, ans = 0, len = nums.size();
        for (int right = 0; right < len; right++) {
            m.insert(nums[right]);
            if (!m.empty() && *m.rbegin() - *m.begin() > limit)
                m.erase(m.find(nums[left++]));

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// Brute force, Time Limit Exceeded
//  class Solution {
//  public:
//      int longestSubarray(vector<int> &nums, int limit) {
//          int len = nums.size(), ans = 0;
//          for (int i = 0; i < len; i++) {
//              int localMax = nums[i];
//              int localMin = nums[i];
//              for (int j = i; j < len; j++) {
//                  localMax = nums[j] > localMax ? nums[j] : localMax;
//                  localMin = nums[j] < localMin ? nums[j] : localMin;
//                  if (abs(localMax - localMin) <= limit)
//                      ans = j - i + 1 > ans ? j - i + 1 : ans;
//              }
//          }
//          return ans;
//      }
//  };
