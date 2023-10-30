class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--) {
            if (dq.size() >= 1) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }

        while (!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> deckRevealedIncreasing(vector<int> &deck) {
//         int n = deck.size(), index = 0;
//         vector<int> ans(n);
//         queue<int> queue;
//         sort(deck.begin(), deck.end());

//         for (int i = 0; i < n; i++)
//             queue.push(i);

//         while (!queue.empty()) {
//             ans[queue.front()] = deck[index++];
//             queue.pop();
//             queue.push(queue.front());
//             queue.pop();
//         }
//         return ans;
//     }
// };