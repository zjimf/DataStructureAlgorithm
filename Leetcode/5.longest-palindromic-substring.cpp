/** 5. Longest Palindromic Substring
 *  @brief dp
 *  @Time_complexity O(N^2)
 */
class Solution {
    bool build(vector<vector<bool>> &dp, int i, int j, string &s) {
        if (i == j) {
            return dp[i][j] = true;
        }
        if (j - i == 1) {
            if (s[i] == s[j]) {
                return dp[i][j] = true;
            } else {
                return dp[i][j] = false;
            }
        }
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
            return dp[i][j] = true;
        } else {
            return dp[i][j] = false;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int startIndex = 0, maxLen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                build(dp, i, j, s);
                if (dp[i][j]) {
                    if (j - i + 1 > maxLen) {
                        startIndex = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLen);
    }
};

/** 5. Longest Palindromic Substring
 *  @brief iterator string, and use two pointer to check
 *  @Time_complexity O(2N^2)
 */
// class Solution {
// private:
//     int left = 0;
//     int maxLen = 0;

// public:
//     string longestPalindrome(string s) {
//         if (s.length() <= 1)
//             return s;

//         for (int i = 0; i < s.length(); i++) {
//             helper(s, i, i);     // for odd
//             helper(s, i, i + 1); // for even
//         }

//         return s.substr(left, maxLen);
//     }

//     void helper(string &s, int l, int r) {
//         while (l >= 0 && r < s.length() && s[l] == s[r]) {
//             if (r - l + 1 > maxLen) {
//                 left = l;
//                 maxLen = r - l + 1;
//             }
//             l--;
//             r++;
//         }
//     }
// };
