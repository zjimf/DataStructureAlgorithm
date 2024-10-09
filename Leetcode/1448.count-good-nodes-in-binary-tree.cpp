/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int find(TreeNode *root, int val) {
        if(!root) return 0;
        int temp = 0;
        if(root->val >= val){
            temp = 1;
        }
        val = max(root->val, val);
        return temp + find(root->left, val) + find(root->right, val);
    }
    int goodNodes(TreeNode *root) {
        return find(root, INT_MIN);
    }
};
// @lc code=end
