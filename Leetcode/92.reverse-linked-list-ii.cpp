/** 92. Reverse Linked List II
 *  @brief split the list(left to right) and reverse it then reconnect
 *
 *  @Time_complexity O(N)
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right)
            return head;
        int len = (right - left) + 1;

        // head doesn't need to reconnect
        if (left == 1)
            return reverse(head, len);

        // set pointers position
        ListNode *prevLeft, *leftPtr, *afterRight, *current = head;
        for (int i = 1; i <= right; i++) {
            if (i == left - 1)
                prevLeft = current;
            else if (i == left)
                leftPtr = current;
            current = current->next;
        }
        afterRight = current;

        // reverse list in range
        ListNode *reversedHead = reverse(leftPtr, len);

        prevLeft->next = reversedHead;
        leftPtr->next = afterRight; // because leftPtr become reversed list tail

        return head;
    }

private:
    ListNode *reverse(ListNode *head, int len) {
        ListNode *temp = head, *prev = nullptr, *current = head, *next = nullptr;
        while (len) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            len--;
        }
        // if there's still have element after right
        temp->next = current;
        return prev;
    }
};