/** 310. Minimum Height Trees
 * @brief 想成衣服掉在地上，抓一個點拿起來的感覺，每輪去除所有leaf直到只剩一到兩個節點
 *
 * https://home.gamer.com.tw/artwork.php?sn=5478747
 * Time_complexity O(V+2E)
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjacentList(n);
        vector<int> inDegree(n, 0), ans;
        // build adjacentList, inDegree table
        for (auto &e : edges) {
            adjacentList[e[0]].push_back(e[1]);
            adjacentList[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }

        // put first round leaf
        queue<int> leafQueue;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) {
                leafQueue.push(i);
                inDegree[i]--;
            }
        }

        // delete leaf every round
        while (!leafQueue.empty()) {
            int qSize = leafQueue.size();
            ans.clear();
            for (int i = 0; i < qSize; i++) {
                int curr = leafQueue.front();
                leafQueue.pop();
                ans.push_back(curr);
                for (auto linked : adjacentList[curr]) {
                    inDegree[linked]--;
                    if (inDegree[linked] == 1)
                        leafQueue.push(linked);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
