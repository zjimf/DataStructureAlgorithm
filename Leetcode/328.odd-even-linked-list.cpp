/** 328. Odd Even Linked List
 * @brief separate connect odd and even, then reconnect
 *
 * Time_complexity O(N)
 */
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode *odd = head, *head2 = head->next, *even = head2;
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = head2;
        return head;
    }
};
