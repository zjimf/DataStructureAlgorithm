/** 147. Sort List
 *  @brief Merge sort
 *
 *  @Time_complexity O(NlogN)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        // Separate list
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        return mergeList(sortList(head), sortList(fast));
    }

private:
    ListNode *mergeList(ListNode *left, ListNode *right) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (left != nullptr && right != nullptr) {

            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        cur->next = (left != nullptr) ? left : right;

        return head->next;
    }
};
// @lc code=end
