class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

// @lc code=end

// @lc code=start
// class Solution {
// public:
//     int findLength(vector<int> &nums1, vector<int> &nums2) {
//         unordered_set<string> set;

//         int len1 = nums1.size();
//         for (int i = 1; i <= len1; i++) { // sliding window len
//             // build string based on sliding window len
//             for (int j = 0; j <= len1 - i; j++) {
//                 string s = "";
//                 for (int k = 0; k < i; k++) {
//                     s += to_string(nums1[j + k]);
//                 }
//                 set.insert(s);
//             }
//         }

//         int len2 = nums2.size();
//         int res = 0;
//         for (int i = 1; i <= len2; i++) {
//             for (int j = 0; j <= len2 - i; j++) {
//                 string s = "";
//                 for (int k = 0; k < i; k++) {
//                     s += to_string(nums2[j + k]);
//                 }
//                 res = max(res, set.count(s) ? i : 0);
//             }
//         }
//         return res;
//     }
// };
// @lc code=end
