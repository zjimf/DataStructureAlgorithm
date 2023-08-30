/** 3. Longest Substring Without Repeating Characters
 *  @brief using Hashmap, sliding window
 * 1. if s[i] not exist in set, store in it
 * 2. if not erase the s[begin] in set, and begin++
 * #  attention to the repetition of i and begin
 *  @Time_complexity O(N)
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans = 0, begin = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            if (!set.count(s[i])) {
                set.insert(s[i]);
                ans = max(ans, i - begin + 1);
            } else {
                while (set.count(s[i]))
                    set.erase(s[begin++]);
                set.insert(s[i]);
            }
        }
        return ans;
    }
};

// With two pointer
//  class Solution {
//  public:
//      int lengthOfLongestSubstring(string s) {
//          unordered_set<char> set;
//          int i = 0, j = 0, n = s.size(), ans = 0;
//          while (i < n && j < n) {
//              if (set.find(s[j]) == set.end()) {
//                  set.insert(s[j++]);
//                  ans = max(ans, j - i);
//              } else {
//                  set.erase(s[i++]);
//              }
//          }
//          return ans;
//      }
//  };
