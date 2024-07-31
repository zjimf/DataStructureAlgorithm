/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head) {
         vector<ListNode*> temp;

        ListNode* curr = head;

        while(curr!=NULL){
            temp.push_back(curr);

            curr = curr->next;
        }


        vector<ListNode*> vec;

        int i =0;
        int j = temp.size()-1;

        while(i<=j)
        {
            if(i==j)
            {
                vec.push_back(temp[i]);

                break;
            }
        
            vec.push_back(temp[i]);
            vec.push_back(temp[j]);

            i++;
            j--;
        }

        head -> next = NULL;

        curr = head;

        for(int i=1;i<vec.size();i++)
        {
            ListNode* t = new ListNode(vec[i]->val);

            curr -> next = t;

            curr = curr -> next;
        }
    }
};
// @lc code=end
