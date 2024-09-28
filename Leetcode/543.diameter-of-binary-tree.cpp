/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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

int height(TreeNode* root, int &res)
{
    if(!root) return 0;
    
    int lHeight = height(root->left, res);
    int rHeight = height(root->right, res);
    
    res= max(res, 1 + lHeight + rHeight);
    return 1+ max(lHeight, rHeight);

}

int diameterOfBinaryTree(TreeNode* root) {
    int res= 0;
    height(root, res);
    return res-1;
}
};
// @lc code=end
