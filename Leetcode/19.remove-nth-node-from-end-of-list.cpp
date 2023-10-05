/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *right = head, *left = head;
        int target = 0;
        while (right != nullptr) {
            right = right->next;
            target++;
        }

        target -= n;
        if (target == 0)
            return left->next;

        while (target != 1) {
            left = left->next;
            target--;
        }
        left->next = left->next->next;

        return head;
    }
};
// @lc code=end
