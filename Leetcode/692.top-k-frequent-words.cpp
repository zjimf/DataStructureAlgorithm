/** 692. Top K Frequent Words
 * @brief priority queue adding pair
 *
 * Time_complexity O(n log(k))
 */
#define pis pair<int, string>

struct cmp {
    bool operator()(pis p1, pis p2) {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> lists;
        priority_queue<pis, vector<pis>, cmp> maxHeap;
        vector<string> v;
        for (auto w : words)
            lists[w]++;

        for (auto list : lists)
            maxHeap.push({list.second, list.first});

        for (int i = 0; i < k; i++) {
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return v;
    }
};
