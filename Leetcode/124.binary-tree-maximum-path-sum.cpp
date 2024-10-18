/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
private:
    int computeMaxPath(TreeNode *root, int &maximumPath) {
        if (!root)
            return 0;

        // 三種情況
        // 左子樹最大路徑
        int leftPath = max(0, computeMaxPath(root->left, maximumPath));

        // 右子樹最大路徑
        int rightPath = max(0, computeMaxPath(root->right, maximumPath));

        // 我 + 左子樹最大路徑 + 右子樹最大路徑
        int currentPath = root->val + leftPath + rightPath;

        maximumPath = max(currentPath, maximumPath);

        // return 要小心，我加上右子樹或左子樹最大值，因為我已經分割了，底下不能再分割
        return root->val + max(leftPath, rightPath);
    }

public:
    int maxPathSum(TreeNode *root) {
        int maximumPath = INT_MIN;
        computeMaxPath(root, maximumPath);
        return maximumPath;
    }
};
// @lc code=end
