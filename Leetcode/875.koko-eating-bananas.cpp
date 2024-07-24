/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
/*
    窮舉法太慢，所以就用1和最大值去做binary search檢驗
 */
class Solution {
public:
    bool check(vector<int> &piles, int mid, int h) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] / mid);
            if (piles[i] % mid != 0)
                ans++;
        }
        return ans <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        sort(piles.begin(), piles.end());
        int len = piles.size();
        int low = 1;
        int high = piles[len - 1];

        while (low < high) {
            int mid = (low + high) / 2;
            if (check(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end
