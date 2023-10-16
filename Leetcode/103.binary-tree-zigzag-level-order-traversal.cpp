/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)
            return vector<vector<int>>();

        vector<vector<int>> res;

        queue<TreeNode *> queue;
        queue.push(root);
        bool leftToRight = true;

        while (!queue.empty()) {
            int size = queue.size();
            vector<int> v(size);
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();

                int index = (leftToRight) ? i : (size - i - 1);
                v[index] = node->val;

                if (node->left != nullptr)
                    queue.push(node->left);

                if (node->right != nullptr)
                    queue.push(node->right);
            }
            leftToRight = !leftToRight;
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end
