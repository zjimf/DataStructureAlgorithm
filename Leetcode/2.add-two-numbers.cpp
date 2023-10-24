/** 2. Add Two Numbers
 *  @brief 每個節點相加，紀錄carry
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            cur->next = node;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            cur = cur->next;
        }

        if (carry == 1) {
            ListNode *node = new ListNode(carry);
            cur->next = node;
        }

        return res->next;
    }
};
