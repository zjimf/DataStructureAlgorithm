/** 395. Longest Substring with At Least K Repeating Characters
 * @brief Recursion, map
 *        1. 先紀錄每個字母出現的次數，以此map作為規範的標準
 *        2. 遍歷string，查看每個字母是否符合規定，直到不符合規定的字母時，設置分割線
 *        3. 再以Recursive去算左右的string的長度即可
 *
 * Time_complexity O(N*logN)
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.length();
        if (len == 0 || len < k)
            return 0;

        if (k <= 1)
            return len;

        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;

        int split = 0;
        while (split < len && map[s[split]] >= k)
            split++;

        if (split == len)
            return len;
        int left = longestSubstring(s.substr(0, split), k);
        int right = longestSubstring(s.substr(split + 1, len - split - 1), k);

        return max(left, right);
    }
};
