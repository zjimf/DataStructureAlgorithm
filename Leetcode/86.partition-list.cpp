/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *l1Ptr = new ListNode(), *l2Ptr = new ListNode(), *l1Head = l1Ptr, *l2Head = l2Ptr, *cur = head;
        while (cur) {
            if (cur->val < x) {
                l1Ptr->next = new ListNode(cur->val);
                l1Ptr = l1Ptr->next;
            } else {
                l2Ptr->next = new ListNode(cur->val);
                l2Ptr = l2Ptr->next;
            }
            cur = cur->next;
        }
        l1Ptr->next = l2Head->next;
        return l1Head->next;
    }
};
// @lc code=end
