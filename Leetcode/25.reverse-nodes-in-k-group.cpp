/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *node = head;
        int count = 0;
        while (node != NULL && count < k) {
            node = node->next;
            count++;
        }

        if (count < k) {
            return head;
        }

        ListNode *next = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int cnt = 0;

        while(curr != NULL && cnt < k){
            next = curr->next;
            curr->next=  prev;
            prev = curr;
            curr = next;
            cnt++; 
        }

        if(next!=NULL){
            head->next = reverseKGroup(next, k);
        }

        return prev;

    }
};
// @lc code=end
