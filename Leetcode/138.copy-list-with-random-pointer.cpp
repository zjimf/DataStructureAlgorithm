/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> oldToNew;

        Node *curr = head;
        while (curr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];

            curr = curr->next;
        }

        return oldToNew[head];
    }
};

// class Solution {
// public:
//     Node *copyRandomList(Node *head) {
//         Node *copyListHead = new Node();

//         Node *copyListCurr = copyListHead;
//         Node *curr = head;

//         copyListHead->val = curr->val;

//         while (curr->next != NULL) {
//             Node *newNode = new Node(curr->next->val);
//             copyListCurr->next = newNode;

//             curr = curr->next;
//             copyListCurr = copyListCurr->next;
//         }
//         copyListCurr->next = NULL;
//     }
// };
// @lc code=end
