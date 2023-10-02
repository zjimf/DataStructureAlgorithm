/** 76. Minimum Window Substring
 *  @brief 以雙指針解題
 *         map<char, int> 紀錄t的各字母出現次數
 *         window<char, int> 紀錄目前雙指針範圍內的各字母出現次數
 *         letterCounter 紀錄雙指針範圍內有出現在map中的字母個數
 *
 *         以fast指針遍歷s,若有找到字母存在於map中,則window[s[fast]]++, letterCounter++
 *         若letterCounter大於等於t的length,表示目前的範圍已經是符合題意的,所以可以紀錄起來並將slow往前找尋下一個符合的範圍
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        if (s.empty() || t.empty()) {
            return result;
        }

        unordered_map<char, int> map;
        unordered_map<char, int> window;

        for (int i = 0; i < t.length(); i++)
            map[t[i]]++;

        int minLength = INT_MAX;
        int letterCounter = 0;

        for (int slow = 0, fast = 0; fast < s.length(); fast++) {
            char c = s[fast];

            // s[i]有在map內
            if (map.find(c) != map.end()) {
                window[c]++;
                if (window[c] <= map[c])
                    letterCounter++;
            }

            // letterCounter已經超過t's length
            if (letterCounter >= t.length()) {
                while (map.find(s[slow]) == map.end() || window[s[slow]] > map[s[slow]]) {
                    window[s[slow]]--;
                    slow++;
                }
                if (fast - slow + 1 < minLength) {
                    minLength = fast - slow + 1;
                    result = s.substr(slow, minLength);
                }
            }
        }
        return result;
    }
};
// @lc code=end
