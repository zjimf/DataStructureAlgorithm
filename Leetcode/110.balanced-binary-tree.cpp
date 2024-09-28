/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool ans;
public:
    int height(TreeNode *root){
        if(!root || !ans)
            return 0;
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        if(abs(lHeight-rHeight)>1){
            ans = false;
        }
        return 1+max(lHeight,rHeight);
    }
    bool isBalanced(TreeNode *root) {
        ans = true;
        int temp = height(root);
        return ans;
    }
};
// @lc code=end
3