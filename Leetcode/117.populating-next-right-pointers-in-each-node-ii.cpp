/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return nullptr;

        queue<Node *> queue;

        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();

            for (int i = 0; i < n; i++) {
                Node *curr = queue.front();
                if (curr->left)
                    queue.push(curr->left);
                if (curr->right)
                    queue.push(curr->right);
                queue.pop();

                if (i == n - 1)
                    curr->next = nullptr;
                else
                    curr->next = queue.front();
            }
        }
        return root;
    }
};
// @lc code=end
