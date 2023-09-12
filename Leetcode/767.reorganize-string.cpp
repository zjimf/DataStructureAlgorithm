/** 767. Reorganize String
 * @brief Record the number of occurrences for each character, stored that in pq
 *        Each time, take out two top values to ensure they are different each time.
 *        Finally, observe the remaining quantity of pq to know how to design the output answer.
 */
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;
        string res;
        for (auto c : s)
            map[c]++;

        for (auto &[c, freq] : map)
            pq.push({freq, c});

        while (pq.size() > 1) {
            auto [freq1, c1] = pq.top();
            pq.pop();
            auto [freq2, c2] = pq.top();
            pq.pop();

            res += c1;
            res += c2;

            if (--freq1 != 0)
                pq.push({freq1, c1});
            if (--freq2 != 0)
                pq.push({freq2, c2});
        }

        if (!pq.empty()) {
            auto [freq, ch] = pq.top();
            if (freq > 1)
                return "";
            res += ch;
        }
        return res;
    }
};
