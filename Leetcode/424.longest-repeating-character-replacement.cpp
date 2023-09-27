class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, maxi = 0, ans = -1;
        unordered_map<char, int> map;
        while (right < n) {
            map[s[right]]++;
            // 目前重複次數最多char出現次數
            maxi = max(maxi, map[s[right]]);
            // 可以替換的char次數是否大於k
            if ((right - left + 1) - maxi > k) {
                map[s[left]]--;
                left++;
            }
            ans = max(ans, (right - left + 1));
            right++;
        }
        return ans;
    }
};
