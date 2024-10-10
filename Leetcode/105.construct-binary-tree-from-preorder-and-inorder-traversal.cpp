/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int preorderIndex = 0;
    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            mapping[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        
        int rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);

        int mid = mapping[rootVal];

        root->left = build(preorder, start, mid-1);
        root->right = build(preorder, mid+1, end);
        
        return root;
    }
};
// @lc code=end

