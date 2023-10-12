/** 42. Trapping Rain Water
 *  @brief
 *  lower紀錄目前l,r經過的最低點（亦即水不會超過這個空間）
 *  level紀錄目前該移動指標值與lower誰較高，那麼level - lower就可以知道該指針的位置可以裝滿多少水
 *  @Time_complexity O(N)
 */
class Solution {
public:
    int trap(vector<int> &height) {
        int l = 0, r = height.size() - 1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};
