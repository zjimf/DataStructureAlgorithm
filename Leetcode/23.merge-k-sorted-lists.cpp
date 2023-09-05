/** 23. Merge k Sorted Lists
 *  @brief Min-heap
 *
 *  @Time_complexity O(N*logN)
 */
struct compare {
    bool operator()(const ListNode *l, const ListNode *r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists)
            if (l)
                q.push({l});

        ListNode pre(0);
        ListNode *node = &pre;
        while (q.size()) {
            ListNode *top = q.top();
            q.pop();
            node->next = top;
            node = node->next;
            if (top->next) {
                q.push(top->next);
            }
        }
        return pre.next;
    }
};
// @lc code=end
