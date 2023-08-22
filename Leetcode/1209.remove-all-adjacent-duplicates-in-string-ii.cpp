/** 1209. Remove All Adjacent Duplicates in String II
 *  @brief vector store the element count and char if count to k then delete
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> v;
        for (auto c : s) {
            if (v.empty() || v.back().first != c) {
                v.push_back({c, 1});
            } else if (++v.back().second == k) {
                v.pop_back();
            }
        }
        string res = "";
        for (auto t : v)
            res.append(t.second, t.first);
        return res;
    }
};
